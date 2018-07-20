#include<stdio.h>
#include <conio.h>
#include<time.h>
#include <string.h>
#include <ctype.h>
#include<windows.h>	
void clrscr(void)
{
   system("cls") ;	//clear screen.
}
int wherex()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&csbi);
	return csbi.dwCursorPosition.X;
}
int wherey()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&csbi);
	return csbi.dwCursorPosition.Y;
}
void gotoxy(short x, short y) 
{
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);		
}
int main()
{
	int n,i,j,x,k,ai[1000],aj[1000],mi=0,mj=0,t;
	printf("enter the size:");
	scanf("%d",&n);
	printf("\n\nTHE REQUIRED OUPUT IS \n\n");
	x=n*2+1;
	t=x;
	for(k=1;k<=n;k++)
	{
		for(i=0;i<x;i++)
		{
			for(j=0;j<x;j++)
				if(i==0 || i==x-1 || j==0 || j==x-1)
				{	ai[mi++]=i;aj[mj++]=j;	}		//printf("*\t");*
			/*	else
					printf("\t");	*/
		//	printf("\n");	
		}
		x-=2;
	//	gotoxy(0,5);
	}
	for(i=0;i<t;i++)
	{
		for(j=0;j<t;j++)
		{
			for(k=0;k<mi;k++)
			{
				if(i==ai[k] && j==aj[k])
					{ printf("* ");break;}
			}
			if(k==mi)
				printf("  ");
		}
		printf("\n");
	}
	
	getch();
}
