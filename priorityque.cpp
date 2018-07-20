

#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	int priority;
	struct node *next;
}node;
typedef struct 
{
	node *first;
}pq;
void create(pq *q)
{
	int ans,d,p;
	while(1)
	{
		printf("\nPress 1 if you want to continue entering else any other key.\n");
		scanf("%d",&ans);
		if(ans!=1)
			break;
		node *nd,*temp=q->first;
		nd=(node*)malloc(sizeof(node));
		nd->next=NULL;
		printf("\nenter data and priority:");
		scanf("%d%d",&d,&p);
		nd->priority=p;
		nd->data=d;
		if(q->first==NULL)
			q->first=nd;
		else if(q->first->priority>p)
		{
			nd->next=q->first;
			q->first=nd;
		}
		else
		{
			while(temp->next!=NULL && temp->next->priority<p)
				temp=temp->next;
			if(temp->next==NULL)
			{
				temp->next=nd;
			}
			else
			{
				nd->next=temp->next;
				temp->next=nd;
			}
		}
	}
}
void display(pq *q)
{
	node *t=q->first;
	if(t==NULL)
	{
		printf("\nlist is empty.\n");
		exit(3);
	}
	printf("\nDATA\tPRIORITY\n");
	while(t!=NULL)
	{
		printf("%d\t%d\n",t->data,t->priority);
		t=t->next;
	}
}
int delq(pq *q)
{
	if(q->first==NULL)
        {
                printf("\nlist is empty.\n");
                exit(5);
        }
	node *t=q->first;
	int d=t->data;
	q->first=t->next;
	free(t);
	return d;

}
int main()
{
	pq q;
	q.first=NULL;
	int ch;
	while(1)
	{
		printf("\n\n1.Create Priority Que.\n2.Display.\n3.Delete\n4.Exit.\n\nEnter choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:create(&q);
				break;
			case 2:display(&q);
				break;
			case 3: printf("%d is deleted",delq(&q));
				break;
			case 4: exit(2);
		}
	}	
}		

