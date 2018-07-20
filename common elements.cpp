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
		nd= createnode(data);
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
node* common(node *l1,node *l2)
{
	node *t1=l1;
	node *t2,*l3=NULL,*nd,*last;
	while(t1!=NULL)
	{
		t2=l2;
		while(t2!=NULL)
		{
			if(t1->data==t2->data)
			{
				nd=createnode(t1->data);
				if(l3==NULL)
					l3=nd;
				else
					last->next=nd;	
			last=nd;
			}	
			t2=t2->next;
		}	
		t1=t1->next;
	}
	return l3;
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
	node *start3;
	start3=common(createlist(),createlist());
	printlist(start3);
}
