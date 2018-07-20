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
void background(int c,int x,int y,int maxlen)
{
	int i,j,k;
	gotoxy(x,y);
	if(c==0)
	{
		for(i=0;i<9;i++)
	    {
	    	ChangeColor(0,7);//changing background.
			 			for(j=0;j<2;j++)
					{
						gotoxy((74-maxlen)/2-2+maxlen+13+j,15+i);	
						printf(" ");
								
					}
					
			ResetConsoleColour(Attributes);
		}
		for(i=0;i<9;i++)
	    {
	    	ChangeColor(0,0);//changing background.
			 		//for(k=0;k<3;k++)
						for(j=0;j<2;j++)
					{
						gotoxy((74-maxlen)/2-2+maxlen+13+j,24+i);	
						printf(" ");
								
					}
				
			ResetConsoleColour(Attributes);
		}	
	}
	else
	{
		for(i=0;i<9;i++)
	    {
	    	ChangeColor(0,0);//changing background.
			 			for(j=0;j<2;j++)
					{
						gotoxy((74-maxlen)/2-2+maxlen+13+j,15+i);	
						printf(" ");
								
					}
					
			ResetConsoleColour(Attributes);
		}
		for(i=0;i<9;i++)
	    {
	    	ChangeColor(0,7);//changing background.
			 		//for(k=0;k<3;k++)
						for(j=0;j<2;j++)
					{
						gotoxy((74-maxlen)/2-2+maxlen+13+j,24+i);	
						printf(" ");
								
					}
				
			ResetConsoleColour(Attributes);
		}		
	}
	ResetConsoleColour(Attributes);
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
           "CASH DEPOSIT",
           "SENIOR CITIZEN",
           "FIXED DEPOSIT",
         } ;
         int n=sizeof(menu)/sizeof(menu[0]);
     int maxlen=0,i,p,j,k,l=0,m=0,r,u=0,c=0;
     for(i=0;i<n;i++)
     {
     	if(strlen(menu[i])>maxlen)
     		maxlen=strlen(menu[i]);
	}
	drawbox(maxlen+6,20,(76-maxlen)/2-2,14);
	drawbox(4,20,(76-maxlen)/2-2+maxlen+11,14);
	background(0,(76-maxlen)/2-2+maxlen+11,14,maxlen);
	   for(i=0;i<6;i++)
	    {
	    	ChangeColor(0,7);//changing background.
			 		for(k=0;k<3;k++)
						for(j=0;j<maxlen+4;j++)
					{
						gotoxy((74-maxlen)/2+j,15+k+l);	
						printf(" ");
								
					}
				l+=3;	
			ResetConsoleColour(Attributes);
		}
		 //for(i=0;i<6;i++)
		l=0;
	/*	gotoxy((76-maxlen)/2-7,wherey()+6);
		printf("ENTER YOU R CHOICE [1/2/3/4/5/6]:-");*/
		while(1)
		{
			c=1;	ShowConsoleCursor(false);
				for(i=u;i<6+u;i++)	
				{
		
	    			if(i==u)
		  			gotoxy((76-maxlen)/2,16);
		 	 	else
		  			gotoxy((76-maxlen)/2,16+3*c++);
		  	
			 ChangeColor(0,7);	
			 printf("%d.",i+1);	
				for(k=0;k<maxlen;k++)
				{
					if(k==0)
					{
						ChangeColor(12,7);
						printf("%c",menu[i][k]);
						ResetConsoleColour(Attributes);
					}
					else
						printf("%c",menu[i][k]);
				}
		//	printf("%d.%s",i+1,menu[i]);
			ResetConsoleColour(Attributes);
		}
				ChangeColor(10,6);//changing background of 1st
				for(i=0;i<3;i++)
					for(j=0;j<maxlen+4;j++)
					{
						gotoxy((74-maxlen)/2+j,15+i+l);	
						printf(" ");
					}
				gotoxy((76-maxlen)/2,16+l);
				printf("%d.",m+1);		//changing background of writing.
				for(k=0;k<maxlen;k++)
				{
					if(k==0)
					{
						ChangeColor(12,6);
						printf("%c",menu[m][k]);
						ResetConsoleColour(Attributes);
					}
					else
						printf("%c",menu[m][k]);
				}
				 ResetConsoleColour(Attributes);
				 r=getKey();
			 	if(r==580)
			 	{
			 		ChangeColor(0,7);
			 		for(i=0;i<3;i++)
						for(j=0;j<maxlen+4;j++)
					{
						gotoxy((74-maxlen)/2+j,15+i+l);	
						printf(" ");
					}
					gotoxy((76-maxlen)/2,16+l);
					printf("%d.",m+1);		//changing background of writing.
					for(k=0;k<maxlen;k++)
					{
						if(k==0)
						{
							ChangeColor(12,7);
							printf("%c",menu[m][k]);
							ResetConsoleColour(Attributes);
						}
						else
							printf("%c",menu[m][k]);
					}
					 ResetConsoleColour(Attributes);
				//	 m=(m+1)%10;
					 //l=(l+3)%18;
					 m++;
					 l+=3;
					 if(l>15)
					 {
					 	if(m<n)
					 	{
						 l=15;
					 	gotoxy(wherex(),wherey()-3);	background(1,(76-maxlen)/2-2+maxlen+11,14,maxlen);
						 u++;}
					 	else{
						 	background(0,(76-maxlen)/2-2+maxlen+11,14,maxlen);
					 	l=0;u=0;}
					 }
					 m=m%n;
					// if(m>5)
						//u++;	
				}
				if(r==572)
			 	{
			 		ChangeColor(0,7);
			 		for(i=0;i<3;i++)
						for(j=0;j<maxlen+4;j++)
					{
						
						gotoxy((74-maxlen)/2+j,15+i+l);	
						printf(" ");
					}
					gotoxy((76-maxlen)/2,16+l);
					printf("%d.",m+1);		
					for(k=0;k<maxlen;k++)
					{
						if(k==0)
						{
							ChangeColor(12,7);
							printf("%c",menu[m][k]);
							ResetConsoleColour(Attributes);
						}
						else
							printf("%c",menu[m][k]);
					}
					 ResetConsoleColour(Attributes);
					 m--;
					 l-=3;
					 
					 if(l<0)
					 {
					 	if(m>=0)
					 	{
						 l=0;
					 	gotoxy(wherex(),wherey()+3);u--;	background(0,(76-maxlen)/2-2+maxlen+11,14,maxlen);}
					 	else{
						 	background(1,(76-maxlen)/2-2+maxlen+11,14,maxlen);
					 	l=15;u=n-6;}
					 }
					 if(m<0)
					 	m=n-1;
					 //if(m>5)
						//u--;	
						
				}
		}
		
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
