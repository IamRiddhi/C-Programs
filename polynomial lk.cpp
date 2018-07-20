#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct node
{
	int coef;
	int exp;
	struct node *next;
}node;
typedef struct
{
	node *first;
}poly;
void initpoly(poly *p)
{
	p->first=NULL;
}
void createpoly(poly *p)
{
	node *nd,*last;
	int e,c;
	char ans;
	while(1)
	{
		printf("enter coefficient:");
		scanf("%d",&c);
		if(c!=0)
		{
			printf("enter exponent:");
			scanf("%d",&e);
			nd=(node*)malloc(sizeof(node));
			if(nd==NULL)
				exit(0);
			nd->coef=c;
			nd->exp=e;
			nd->next=NULL;
			if(p->first==NULL)
				p->first=nd;
			else
				last->next=nd;
			last=nd;			
		}
		printf("Do you want to continue?(y/n):");
		fflush(stdin);
		scanf("%c",&ans);
		if(ans!='Y' && ans!='y')
			break;
	}
}
void printpoly(poly *p)
{
	node *t=p->first;
	int c,e;
	while(t!=NULL)
	{
		c=t->coef;
		e=t->exp;
		if(c>0 && t!=p->first)
			printf("+");
		 if(c!=1 && c!=-1)
		 	printf("%d",c);
		if(c==-1)
			printf("-");
		if(e!=0)
		{
			printf("x");
			if(e!=1)
				printf("^%d",e);
		}
		if(e==0 && c==1 || e==0 && c==-1)
			printf("1");			 	
		t=t->next;
	}
}
int main()
{
	poly p;
	initpoly(&p);
	createpoly(&p);
	printpoly(&p);
}
