#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
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
int main()
{
	char name[]="Riddhi";
	int px,py,ch=0,x=37,y=12;
	gotoxy(x,y);
	printf("%s",name);
	while(ch!=27)//escape=27
	{
		ch=getch();
		px=x;
		py=y;
		switch(ch)
		{
			case 'w':
			case 'W':
			y--;
			break;
			
			case 'a':
			case 'A':
			x--;
			break;
			
			case 's':
			case 'S':
			y++;	
			break;
			
			case 'd':
			case 'D':
			x++;	
			break;
					
		}
		if(x<1)
			x=74;
		if(y<1)
			y=25;
		if(x>74)
			x=1;
		if(y>25)
			y=1;	
		gotoxy(px,py); printf("%s","      ");
		gotoxy(x,y); printf("%s",name);
	}
}
