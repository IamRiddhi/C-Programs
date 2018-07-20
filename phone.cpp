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
	int ch,i,j,c,k,px,py,cx,cy,tx,ty,ix,s;int w[100];
	int p[][10]={
			{9,0,3,8,9,6,3,2,7,1},
			{8,0,1,7,6,1,0,8,7,1},
			{8,5,8,4,9,0,5,8,0,8},
			{9,9,0,3,6,2,7,3,1,7},
			{9,1,6,3,8,7,8,2,4,8},
			{8,2,7,6,8,4,1,3,0,0},
			{9,2,3,9,2,0,8,0,8,8}
			};
	char x[][20]={"Riddhi       ","Debdeep      ","Subharghyo     ","Debanjan     ","Shaswati    ","Shatavisha","Suvam          "};
	printf("SEARCHING BY NO\n\n");
/*	while(1)
	{
		c=getch();
		c-='0';
		if(c<1 || c>2)
			printf("\a");
		else
		{
			printf("%d",c);
		//	printf("\n start\n");
			break;
		}	
	}
	
	switch(c)
	{
		case 1:*/
		 	for(j=0;j<10;j++)
				{
					while(1)
					{
						ch=getch();
							ch-='0';
						if(ch==0 && j==0)
							printf("\a");
						else
							break;
					}
					printf("%d",ch);
					px=wherex();
					py=wherey();
					gotoxy(0,10);
					for(i=0;i<7;i++)
					{
						if(p[i][j]==ch)
							{	
								if(j!=0 && w[i]!=-1)
									{
									//	w[i]=0;
										continue;
									}
									
								for(k=0;k<10;k++)
								{
									
									printf("%d",p[i][k]);
									//tx[s]=wherex();ty[s]=wherey();
									//ix=i;
								}
								//for(k=0;k<s;k++)
								//{
								//	gotoxy(tx[k],ty[k]);
									printf("- ");
									puts(x[i]);
								//}
								w[i]=-1;
								//printf("\n");
							}
					
							else
							{
								w[i]=0;
							}
					}	
						
							if(wherey()<cy && j>0)
							{
								cy-=wherey();
								for(k=1;k<=cy;k++)
								{	
								printf("                                 \n");
								}
							}
							cy=wherey();
							if(w[0]==0 && w[1]==0 && w[2]==0 && w[3]==0 && w[4]==0 && w[5]==0 && w[6]==0)
						{
							gotoxy(0,10);
							printf("MATCH NOT FOUND");
							break;
						}
						gotoxy(px,py);
														
				
				}
	//}
	getch();
}
