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
void SetConsoleColour(WORD* Attributes, DWORD Colour)
{
    CONSOLE_SCREEN_BUFFER_INFO Info;
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hStdout, &Info);
    *Attributes = Info.wAttributes;
    SetConsoleTextAttribute(hStdout, Colour);
}

void ResetConsoleColour(WORD Attributes)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Attributes);
}
void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}
WORD Attributes = 0;
#define ChangeColor(f,b) SetConsoleColour(&Attributes,(f) | ((b)<<4))
int getKey(void)
{
    int ch = getch();
    if (ch == 0 || ch == 224)
        ch = 500 + getch();
    return ch;
}
void background1(int c,int r)
{
	int i,j,m,p;
	m=c/4;
	p=c/10;
	ChangeColor(0,2);
	for(i=0;i<r;i++)
	{
		for(j=0;j<m;j++)
		{
			gotoxy(p+j,0+i);
			printf(" ");
		}
	}
	ResetConsoleColour(Attributes);
}
void background2(int c,int r)
{
	int i,j,m,l;
	m=c/4;
	l=c-(c/10)-m;
	ChangeColor(0,2);
	for(i=0;i<r;i++)
	{
		for(j=0;j<m;j++)
		{
			gotoxy(l+j,0+i);
			printf(" ");
		}
	}
	ResetConsoleColour(Attributes);
}
void drawbox(int w,int h,int x,int y,int color)
{
	int i,j,ux,uy;
	ChangeColor(0,color);
	for(i=0;i<h;i++)
	{
		for(j=0;j<w;j++)
		{
			gotoxy(x+j,y+i);
			printf(" ");
		}
	}
	//ResetConsoleColour(Attributes);
	gotoxy(x,y);
	printf("%c",218);
	gotoxy(x+w-1,y);	
	printf("%c",191);
	gotoxy(x,y+h-1);	
	printf("%c",192);
	gotoxy(x+w-1,y+h-1);
	printf("%c",217);
	for(i=1;i<w-1;i++)
	{
		gotoxy(x+i,y);	
		printf("%c",196);
		gotoxy(x+i,y+h-1);
		printf("%c",196);
	}
	for(i=1;i<h-1;i++)
	{
		gotoxy(x,y+i);	
		printf("%c",179);
		gotoxy(x+w-1,y+i);	
			printf("%c",179);
	}
	printf("\n");
	ResetConsoleColour(Attributes);
}
void backgroundmid(int c,int r)
{
	int i,j,m,l;
	m=(3*c)/10;
	l=c/10+c/4+1;
	ChangeColor(0,7);
	for(i=0;i<r;i++)
	{
		for(j=0;j<m-1;j++)
		{
			gotoxy(l+j,0+i);
			printf(" ");
		}
	}
	m/=3;
	m-=2;
	for(i=0;i<55;i+=10)
	drawbox(1,6,l+m,i,0);
	for(i=0;i<55;i+=10)
	drawbox(1,6,l+(2*m)+2,i,0);
	ResetConsoleColour(Attributes);
}
int main() 
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int c, r;
	ShowConsoleCursor(false);
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    c = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    r= csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	background1(c,r);
	background2(c,r);
	backgroundmid(c,r);
	//drawbox(5,5,c/10+c/4+10,r/2,12);
	gotoxy(0,0);
	ShowConsoleCursor(false);
	getch();
}
