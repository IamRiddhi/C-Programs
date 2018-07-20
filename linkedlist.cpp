#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}node;
node* createnode(int d)
{
	node *nd;
	nd=(node*)malloc(sizeof(node));
	nd->data=d;
	nd->next=NULL;
	return nd;
}
node* createlist()
{
	int data;char ans;
	node *first,*last,*nd;
	first=NULL;
	while(1)
	{
		printf("enter data:-");
		scanf("%d",&data);
		nd=	createnode(data);
		if(first==NULL)
			first=nd;
		else
			last->next=nd;
		last=nd;
		printf("do you want to continue(Y\N)?");
		fflush(stdin);
		scanf("%c",&ans);
		if(ans!='y' && ans!='Y')
			break;
	}
	return first;
}
void printlist(node *first)
{
	node *t=first;
	while(t!=NULL)
	{
		printf("%d\t",t->data);
		t=t->next;
	 } 
}
int main()
{
	int c; node *start;
	start=NULL;
	while(1)
	{
		printf("1.create\n2.print\n3.exit\n");
		printf("enter choice:-");
		scanf("%d",&c);
		switch(c)
		{
			case 1: start=createlist();
						break;
			case 2:	printlist(start);
						break;
			case 3: exit(1);				
		}
	}
}
