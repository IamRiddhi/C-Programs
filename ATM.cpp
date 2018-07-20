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
void drawbox(int w,int h,int x,int y)
{
	int i,ux,uy;
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
void showMenu()
{
	 char menu[][50] = {
	 	"SERVICES",
           "BANKING",
           "MINI STATEMENT",
           "BALANCE INFO",
           "MOBILE REGISTRATION",
           "TRANSFER",
         } ;
     int maxlen=0,i;
     for(i=0;i<6;i++)
     {
     	if(strlen(menu[i])>maxlen)
     		maxlen=strlen(menu[i]);
	}
	drawbox(maxlen+6,20,(76-maxlen)/2-2,14);
	   for(i=0;i<6;i++)
	    {
	    		if(i==0)
		  		gotoxy((76-maxlen)/2,16);
		  	else
		  		gotoxy((76-maxlen)/2,16+3*i);
			printf("%d.%s",i+1,menu[i]);
		}
		gotoxy((76-maxlen)/2-7,wherey()+6);
		printf("ENTER YOUR CHOICE [1/2/3/4/5/6]:-");
}

int len(char *a)
{
	int l;
	l=strlen(a);
	return l;
}
void printhead()
{
	char a[]="WELCOME TO STATE BANK OF INDIA";
	int l,x;
	l=len(a);
	x=(75-l)/2;
	drawbox(l+4,5,x,1);
	gotoxy(x+2,3);
	printf("%s",a);
}
void banking()
{
	int l,c,maxlen=0,i;
	char b[]="PLEASE CHOOSE YOUR DESIRED LANGUAGE:";
	char menu[][10]={"ENGLISH",
				"HINDI"};
	clrscr();
	printhead();
	gotoxy((75-strlen(b))/2+2,10);
	printf("%s",b);
	for(i=0;i<2;i++)
     {
     	if(strlen(menu[i])>maxlen)
     		maxlen=strlen(menu[i]);
	}
	drawbox(maxlen+6,8,(76-maxlen)/2-2,14);
	for(i=0;i<2;i++)
	    {
	    		if(i==0)
		  		gotoxy((76-maxlen)/2,16);
		  	else
		  		gotoxy((76-maxlen)/2,16+3*i);
			printf("%d.%s",i+1,menu[i]);
		}
		gotoxy((76-maxlen)/2-7,wherey()+6);
		printf("ENTER YOUR CHOICE [1/2]:-");
		
		while(1)
		{
			c=getch();
			c-='0';
			if(c<1 || c>2)
			{
				printf("\a");
			}
			else if(c==2)
			{
				printf("%d",c);
				//gotoxy(0,wherey()+3);
				printf("\n\n\nTHIS SERVICE IS TEMPORARY UNAVAILABLE. PLEASE CHOOSE ENGLISH TO CONINUE.\n\n");
			}
			else
			{
				printf("%d",c);
				break;
			}
		}
		
}
int main()
{
	int u,c,l;
	char a[]="PLEASE SWIPE YOUR CARD BY PRESSING 0.";
	printhead();
	l=strlen(a);
	gotoxy((75-l)/2+2,10);
	printf("%s",a);
	while(1)
	{
		printf("\n\n\n");
		u=getch();
		u-='0';
		if(u!=0)
		{
			printf("\a \n\n\nCARD NOT RECOGNISED.PLEASE SWAP AGAIN.");
		}
		else
			break;
	}
	clrscr();
	printhead();
	gotoxy(16,9);
	printf("PLEASE CHOOSE \"BANKING\" FOR CASH \"WITHDRAWLS\"");
//	drawbox(25,20,26,14);
	showMenu();
	while(1)
	{
		c=getch();
		c-='0';
		if(c<1 || c>6)
			printf("\a");
		else
		{
			printf("%d",c);
			break;
		}
	}
	switch(c)
	{
		case 2:banking();
	}
//	getch();
}
