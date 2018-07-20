#include<stdio.h>
#include<malloc.h>
#include<windows.h>
#include<stdlib.h>
typedef struct
{
	int row;
	int col;
	int val;
}elem;
typedef struct
{
	int rows;
	int cols;
	elem *ar;
	int n; 	//no of elements excluding 0.
}sparse;

void clrscr(void)
{
   system("cls") ;	//clear screen.
}
void gotoxy(short x, short y) 
{
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);		
}
void drawbox()
{
	int w=30,h=12,i,x=1,y=1;
	gotoxy(x,y);
		putchar('É');
	gotoxy(x+w-1,y);	
	putchar('»');
	gotoxy(x,y+h-1);	
		putchar('È');
	gotoxy(x+w-1,y+h-1);
		putchar('¼');
	for(i=1;i<w-1;i++)
	{
		gotoxy(x+i,y);	
		putchar('Í');
		gotoxy(x+i,y+h-1);
			putchar('Í');
	}
	for(i=1;i<h-1;i++)
	{
		gotoxy(x,y+i);	
			putchar('º');
		gotoxy(x+w-1,y+i);	
			putchar('º');
	}
	printf("\n");
}
void createsparse(sparse *sp)
{
	int i; 
	printf("enter no of inputs:-");
	scanf("%d",&sp->n);
	printf("enter no of rows of original matrix:-");
	scanf("%d",&sp->rows);
	printf("enter no of columns of original matrix:-");
	scanf("%d",&sp->cols);
	sp->ar=(elem*)malloc(sp->n*sizeof(elem));
	for(i=0;i<sp->n;i++)
	{
		printf("enter in which row you want to enter the no:-");
		scanf("%d",&sp->ar[i].row);
		printf("enter in which column you want to enter the no:-");
		scanf("%d",&sp->ar[i].col);
		printf("enter the no:-");
		scanf("%d",&sp->ar[i].val);
	}	
}

void printsparse(sparse *sp)
{
	
	int i,j,k=0,m=0;
	clrscr();
	
	
	for(i=0;i<sp->rows;i++)
	{

		for(j=0;j<sp->cols;j++)
		{
			if(k<sp->n && sp->ar[k].row==i && sp->ar[k].col==j)
			{
				printf("%d\t",sp->ar[k].val);
				k++;
			}
			else
			{
				printf("0\t");
				}	
		}
		printf("\n");
		 
	}
}
int main()
{
	sparse s;
	int c;
	while(1)
	{
		printf("1.Create Sparse Matrix\n2.Print Original Matrix\n3.Exit.\n");
		printf("enter choice:-");
		scanf("%d",&c);
		switch(c)
		{
			case 1: createsparse(&s);	
					break;
			case 2: printsparse(&s);
					break;
			case 3: exit(1);		
		}
	}
}
