#include<stdio.h>
#include<stdlib.h>
typedef struct sparse
{
	int data;
	int i;
	int j;
	struct sparse *col;
	struct sparse *row;
}sparse;
void initsparse(sparse *sp)
{
	sp->col=NULL;
	sp->row=NULL;
}
void createcol(sparse **start,int j)
{
	sparse *nd,*last;
	int i;
	for(i=0;i<j;i++)
	{
		nd=(sparse*)malloc(sizeof(sparse));
		if(nd==NULL)
		{
			printf("out of space");
			exit(1);
			}	
		nd->j=i+1;
		nd->i=0;		
		if(*start==NULL)
			*start=nd;
		else
			last->col=nd;
		last=nd;	
	}	
	last->col=*start;	
}
void createrow(sparse **start,int j)
{
	sparse *nd,*last;
	int i;
	for(i=0;i<j;i++)
	{
		nd=(sparse*)malloc(sizeof(sparse));
		if(nd==NULL)
		{
			printf("out of space");
			exit(1);
			}	
		nd->i=i+1;
		nd->j=0;		
		if(*start=NULL)
			*start=nd;
		else
			last->row=nd;
		last=nd;	
	}	
	last->row=*start;	
}
void createsparse(sparse *header)
{
	sparse *sp;
	printf("how many rows and columns?-");
	scanf("%d%d",&header->i,&header->j);
	createcol(&header->col,header->j);
	createrow(&header->row,header->i);
}
int main()
{
	sparse s;
	initsparse(&s);
	createsparse(&s);
}
