#include<stdio.h>
#include<stdlib.h>
#define MAX 10
typedef struct 
{
	int a[MAX];
	int front;
	int rear;
}cque;
void initque(cque *q)
{
	q->front=0;
	q->rear=0;
}
void insert(cque *q,int d)
{
	if((q->rear+1)%MAX==q->front)
	{
		printf("queue is full");
		exit(0);
	}
	q->rear=(q->rear+1)%MAX;
	q->a[q->rear]=d;
}
int delt(cque *q)
{
	if(q->front==q->rear)
	{
		printf("queue is empty");
		exit(1);
	}
	q->front=(q->front+1)%MAX;
	return q->a[q->front];
}
int peep(cque *q)
{
	if(q->front==q->rear)
	{
		printf("queue is empty");
		exit(1);
	}
	return q->a[q->rear];
}

void printque(cque *q)
{
	int f;
	f=q->front;
	while(f!=q->rear)
	{
		f=(f+1)%MAX;
		printf("%d\n",q->a[f]);
	}
}
int main()
{
	int ch,d;
	cque q;
	initque(&q);
	while(1)
	{
		printf("\n\n1.Insert\n2.Delete\n3.Peep\n4.Print\n5.Exit\n");
		printf("\nenter choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("\nenter data:");
					scanf("%d",&d);
					insert(&q,d);
					break;
			case 2:printf("the deleted element is %d",delt(&q));
				break;
			case 3:	printf("the peeped element is %d",peep(&q));
				break;
			case 4:	printque(&q);
				break;
			
			case 5: exit(2);			
		}
	}
}
