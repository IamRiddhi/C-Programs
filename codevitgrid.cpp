#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void displaypathtoprincess(char **a,int n)
{
	int i,j,pi,pj,mi,mj,cj=-1,ci=-1;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i][j]=='m')
			{
					mi=i;
					mj=j;
			}
			if(a[i][j]=='p')
			{
				pi=i;
				pj=j;
			}	
		}
	}
	//	printf("%d,%d    %d,%d",mi,mj,pi,pj);
	while(1)
	{
		if(mi<pi)
			ci=1;
		else if(mi>pi)
			ci=2;	
		switch(ci)
		{
		case 1:
				mi++;
				printf("DOWN\n");
				break;
		case 2:   mi--;
				printf("UP\n");
				break;
		}
		ci=-1;
		if(mj<pj)
			cj=3;
		else if(mj>pj)
			cj=4;		
		switch(cj)
		{
			case 3:   mj++;
					printf("RIGHT\n");
					break;
			case 4:   mj--;
					printf("LEFT\n");
					break;		
		}	
		cj=-1;				
		if(mi==pi && mj==pj)
			break;
	}
}
int main()
{
	int j,i,n;
	char **g;
	printf("enter size:");
	scanf("%d",&n);
	g=(char**)malloc(n*sizeof(char*));
	for(i=0;i<n;i++)
		g[i]=(char*)malloc((n+1)*sizeof(char));
	for(i=0;i<n;i++)
	{
		
			fflush(stdin);
			gets(g[i]);
			puts("");
	}
	displaypathtoprincess(g,n);
	/*for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%c\t",g[i][j]);
		}
	printf("\n");	
	}*/
}
