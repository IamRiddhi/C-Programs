#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define HEADSIZE sizeof(int)
typedef struct
{
	int deleted;
	char name[100];
	int age;
	float sal;
	int id;
}emp;
void inputdata(emp *ep)
{
	printf("enter employee's name:");
	fflush(stdin);
	gets(ep->name);
	printf("enter employee's age:");
	scanf("%d",&ep->age);
	printf("enter employee's salary:");
	scanf("%f",&ep->sal);
	printf("enter employee's id:");
	scanf("%d",&ep->id);
	ep->deleted=0;
}
void printdata(emp *e)
{
	printf(" employee's name is %s\nage is %d\nsalary is %7.2f\nid is %d\n",e->name,e->age,e->sal,e->id);
}
/*int searchbyname(FILE *fp,char *name)
{
	emp e;
	while(!feof(fp))
	{
		fread(&e,sizeof(emp),1,fp);
		if(!e.deleted && strcmpi(e.name,name))
		{			
			fseek(fp,-sizeof(emp),SEEK_CUR);
			return 1;
		}	
	}
		return 0;		
}*/
int main()
{
	int ch,i,nrec=0;
	char name[50];
	emp e;
	const char *a="c:\\users\\lenovo\\desktop\\riddhi.txt";
	FILE *fp;
	fp=fopen(a,"r+b"); //if file exists open in read-write mode.(read is piority)
	if(fp==NULL)	//file does not exist.write-read mode.
		{
			fclose(fp);
			fp=fopen(a,"w+b");
				
		}
		else			
		{
			fseek(fp,0,SEEK_SET);
			fread(&nrec,sizeof(int),1,fp);
			printf("no of records=%d\n",nrec);
		}
	
	while(1)
	{
		printf("1.Add\n2.Display all\n3.Search by id\n4.Dispaly ith record\n5.Search by name\n6.Edit\n7.Delete\n8.Exit\n");
		printf("enter choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: inputdata(&e);		 //Add record.
					fseek(fp,0,SEEK_SET);
					nrec++;
					printf("from add,nrec=%d\n",nrec);
					fwrite(&nrec,sizeof(int),1,fp);
					fseek(fp,HEADSIZE+(nrec-1)*sizeof(emp),SEEK_SET);  
					fwrite(&e,sizeof(emp),1,fp);
					break;
			case 2: fseek(fp,HEADSIZE,SEEK_SET);	//Display All.
					printf("display all,nrec=%d\n",nrec);
					for(i=1;i<=nrec;i++)
					{
						fread(&e,sizeof(emp),1,fp);
						if(!e.deleted)
							printdata(&e);	
					}
					break;
			case 3: int id;					//Search by id.
					printf("enter id you want to search:");
					scanf("%d",&id);
					fseek(fp,HEADSIZE,SEEK_SET);
					for(i=1;i<=nrec;i++)
					{
						fread(&e,sizeof(emp),1,fp);
						if(!e.deleted && e.id==id)
						{
							printdata(&e);
							break;
						}
					}
					if(i>nrec)
						printf("Record not found");
					break;
			case 4:	int p; 		//Display ith record.
					printf("enter record no you want to display:");
					scanf("%d",&p);
					if(p<=nrec)
					{
						fseek(fp,HEADSIZE+(p-1)*sizeof(emp),SEEK_SET);
						fread(&e,sizeof(emp),1,fp);
						printdata(&e);
					}
					else
						printf("Record not found");
					break;						
			case 5:  			//Search by name.
					printf("enter the name you want to search:");
					gets(name);
					fseek(fp,HEADSIZE,SEEK_SET);
					for(i=1;i<=nrec;i++)
					{
						fread(&e,sizeof(emp),1,fp);
						if(!e.deleted && strcmpi(e.name,name)==0)
						{
							printdata(&e);
							break;
						}
					}
					if(i>nrec)
						printf("Record not found");
					break;
			case 6:  			//Edit by name.
					printf("enter the name you want to edit:");
					fflush(stdin);
					gets(name);
					fseek(fp,HEADSIZE,SEEK_SET);
					for(i=1;i<=nrec;i++)
					{
						fread(&e,sizeof(emp),1,fp);
						if(!e.deleted && strcmpi(e.name,name)==0)
						{
							fseek(fp,-sizeof(emp),SEEK_CUR);
							inputdata(&e);
							fwrite(&e,sizeof(emp),1,fp);
							break;
						}
					}
					if(i>nrec)
						printf("Record not found");
					break;	
			case 7:  			//Delete by name.
					printf("enter the name you want to delete:");
					fflush(stdin);
					gets(name);
					fseek(fp,HEADSIZE,SEEK_SET);
					for(i=1;i<=nrec;i++)
					{
						fread(&e,sizeof(emp),1,fp);
						if(!e.deleted && strcmpi(e.name,name)==0)
						{
							e.deleted=1;
							fseek(fp,-sizeof(emp),SEEK_CUR);
							fwrite(&e,sizeof(emp),1,fp);
							printf("%dth record deleted\n",i);
							break;
						}
					}
					if(i>nrec)
						printf("Record not found");
					break;
			case 8: exit(1);
		}
	}
}
