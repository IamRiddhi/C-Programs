#include<stdio.h>
#include<malloc.h> 
#include<stdlib.h>
#include<string.h>
typedef struct node
{
	int id;
	int roll;
	char name[100];
	int year;
	char dept[3];
	char section; 
	struct node *next; 
    
}node; 

node* createnode(int i,int r,char *nm,int yr,char *dpt,char sctn)
{
	 node *nd; 
	 nd=(node*)malloc(sizeof(node)); 
	 nd->roll=r;
	 nd->id=i;
	 strcpy(nd->name,nm);
	 nd->year=yr;
	 strcpy(nd->dept,dpt);
	 nd->section=sctn;
	 nd->next=NULL;
	return nd; 
}
node* createlist()
{
	int r,stid;char nm[100];int yr;char dpt[3];char sctn;
	char ans;
	 node *first,*last,*nd; 
	 first=NULL; 
	 while(1)
	{
		printf("enter Student ID:-"); 
		scanf("%d",&stid);
		printf("enter Roll Number:-"); 
		scanf("%d",&r);
		printf("enter Student Name:-"); 
		fflush(stdin);
		gets(nm);
		fflush(stdin);
		printf("enter Year:-"); 
		scanf("%d",&yr);
		printf("enter Department:-"); 
		scanf("%s",dpt);
		fflush(stdin);
		printf("enter Section:-"); 
		scanf("%c",&sctn);
		 
		nd=	createnode(stid,r,nm,yr,dpt,sctn); 
		if(first==NULL) 
			first=nd;
		else 
			last->next=nd;
		last=nd;
		printf("do you want to continue(Y/N)?");
		fflush(stdin); 
		scanf("%c",&ans);
		if(ans!='y' && ans!='Y') 
		 	break;
	}
return first;
}

void insertatlast(node *first)
{ 
	node *nd,*t;
    int stid,r;char nm[100];int yr;char dpt[3];char sctn;
    printf("enter Student ID:-"); 
    scanf("%d",&stid);
    printf("enter Roll Number:-"); 
	scanf("%d",&r);
	printf("enter Student Name:-"); 
	fflush(stdin);
	gets(nm);
	fflush(stdin); 
	printf("enter Year:-"); 
	scanf("%d",&yr); 
	printf("enter Department:-"); 
	scanf("%s",dpt);
	fflush(stdin);
	printf("enter Section:-"); 
	scanf("%c",&sctn);
	 
	nd=	createnode(stid,r,nm,yr,dpt,sctn); 
	
	t=first;
	while(t->next!=NULL)
	{
		 t=t->next; 
	} 
	t->next=nd; 
	nd->next=NULL;
}


void delanywhere(node **first)
{
    node *prev,*t;
    int c=0,stid;
	prev=NULL;
	 t=*first; 
	 printf("enter Student ID to delete:");
	 scanf("%d",&stid);

	  while(t!=NULL)
	{ 
		if(stid==t->id)
			break;
		prev=t;
		t=t->next; 
	} 
	if(prev!=NULL)
	{
	 prev->next=t->next; 
	 free(t);
	}
	else
	{
		*first=t->next;
		free(t);
	}
	printf("\n Record Deleted.");
}
void printlist(node *first)
{
	
	node *t=first;
	printf("\n\nID\tRoll\tYear\tSection\tDepartment\tName\n\n");
     while(t!=NULL)
	{
		printf("%d\t%d\t%d\t%c\t  %s\b\t\t%s\n",t->id,t->roll,t->year,t->section,t->dept,t->name); 
		t=t->next;
	}	 
}
void studentCount(node* first)
{
	int count=0;
	while(first!= NULL)
	{
		count++;
		first=first->next;
	}
	printf("\nThe Total Student Count is %d\n", count);
}
 int main()
{
	int c;
	node *start;
    start=NULL;
	while(1)
	{
		printf("\n\n1.Create Student Database\n2.View Database\n3.Add Student\n4.Remove Student\n5.Check Student Count\n6.Exit Application\n");
		printf("\nEnter Your Choice:-"); 
		scanf("%d",&c); 
		switch(c)
		{
			case 1: start=createlist();
			        break;
			case 2: printlist(start);
			        break;
			case 3: insertatlast(start); 
			        break;
			case 4: delanywhere(&start);
			        break;
			case 5: studentCount(start);
			        break;
			case 6: printf("\nDeveloped By Diptonil Sinha, Somsubhra Chakraborty & Soumalya Saha @2017\n");
			exit(1);
			
		}
	}
	return 0;
}
 
