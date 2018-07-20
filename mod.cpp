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
		printf("do you want to continue(Y/N)?");
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
void printreverse(node *first,node *last)
{
	node *temp;
	while(first!=last)
	{
		temp=first;
		while(temp->next!=last)
			temp=temp->next;
		if(temp->next==last)	
			printf("%d\t",temp->data);
		else
			printf("%d->",temp->data);		
	 last=temp;	
	}
	printf("\n");
}
void soham(node *first)
{
	int k,i;
	node *temp=first,*x=first;
	printf("enter the value of k:");
	scanf("%d",&k);
	while(x!=NULL)
	{
		temp=x;
		for(i=1;i<=k;i++)
		{
			temp=temp->next;
		}
		printreverse(x,temp);
		x=temp;
	}
}
int main()
{
	int c; node *start;
	start=NULL;
	while(1)
	{
		printf("\n1.create\n2.print\n3.Print Reverse\n4.soham\n 5.exit\n");
		printf("enter choice:-");
		scanf("%d",&c);
		switch(c)
		{
			case 1: start=createlist();
						break;
			case 2:	printlist(start);
						break;
			case 3:	printreverse(start,NULL);
					break;											
			case 4: soham(start);
					break;
			case 5: exit(1);						
		}
	}
}
	
	
