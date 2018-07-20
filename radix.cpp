#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<malloc.h>
#include<windows.h>
void clrscr(void)
{
   system("cls") ;	//clear screen.
}
void gotoxy(short x, short y) 
{
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);		
}
typedef struct node
{
	int no;
	node *next;
}node;
typedef struct
{
	node *front;
	node  *rear;
}que;
void init(que *qp)
{
	qp->front=NULL;
	qp->rear=NULL;
}
int isfull(que *qp)
{
	return 0;
}
int isempty(que *qp)
{
	 if(qp->front==NULL)
	 	return 1;
	 else 
	 	return 0;	
}
void insert(que *qp,int n)
{
	node *nd;
	nd=(node*)malloc(sizeof(node));
	if(nd==NULL)
	{
			printf("\n\nQUEUE IS FULL.");
			exit(1);
	}
	nd->no=n;
	nd->next=NULL;
	if(isempty(qp))     //que is empty.
	{
		qp->front=nd;
	}
	else
	{
		qp->rear->next=nd;
	}
	qp->rear=nd;
}
int remove(que *qp)
{
	node *t;
	int x;
	if(isempty(qp))
		exit(2);
	t=qp->front;
	x=t->no;
	qp->front=qp->front->next;
	free(t);
	if(qp->front==NULL)
		qp->rear=NULL;
	return x;		
}
void printque(que *qp)
{
	node *t=qp->front;
	while(t!=NULL)
	{
		printf("%d\n",t->no);
		t=t->next;
	}
}
int highest(int *a,int n)
{
	int i,h;
	h=a[0];
	for(i=1;i<n;i++)
	{
		if(a[i]>h)
			h=a[i];
	}
	return h;
}
int countdigits(int n)
{
	int c=0;
	while(n!=0)
	{
		n=n/10;
		c++;
	}
	return c;
}
int currentdigit(int n,int pos) //pos counted from end.
{
	int x=0;
	while(x<pos-1)
	{
		n=n/10;
		x++;
	}
	n=n%10;
	return n;
}
int* radixsort(int *a,int n)
{
	int   i,j,m,c;
	que *q;
	q=(que*)malloc(10*sizeof(que));
	c=countdigits(highest(a,n));
	for(i=0;i<10;i++)  //creating array of ques.
		{		
			init(&q[i]);
		}
	for(j=1;j<=c;j++)			//no of iterations
	{
		for(i=0;i<n;i++)
		{
			insert(&q[currentdigit(a[i],j)],a[i]);
		}
		m=0;
		for(i=0;i<n;i++)
		{	
			while(isempty(&q[m]))
				m++;			
			a[i]=remove(&q[m]);
		}
	}
		free(q);
	/*for(i=0;i<n;i++)
		free(&q[i]);*/
	return a;
}
int main()
{
	int i,*a,n;
	for(i=0;i<80;i++)
		printf("-");	
	gotoxy(30,2);	
	printf(" RADIX SORT\n\n");
	for(i=0;i<80;i++)
		printf("-");
	printf("\n\nHOW MANY ELEMENTS YOU WANT TO SORT?");
	scanf("%d",&n);
	a=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		printf("\nENTER %dth ELEMENT:",i+1);
		scanf("%d",&a[i]);
	}
	printf("\nTHE SORTED ELEMENTS ARE : \n\n");
	a=radixsort(a,n);
		for(i=0;i<n;i++)
			printf("%d\n\n",a[i]);	
	printf("\n\nPRESS ANY KEY TO CONTINUE");
	getch() ;

			clrscr();
		for(i=0;i<80;i++)
		printf("-");	
		gotoxy(25,2);	
		printf(" THANK YOU!");
		gotoxy(0,4);
		for(i=0;i<80;i++)
		printf("-");
}
