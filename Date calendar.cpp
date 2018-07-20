#include<stdio.h>
#include<string.h>
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

int isleap(int year)
{
	return (year%400==0) || (year%100!=0 && year%4==0);
}
int dowjan1after(int y)//returns day of week no for 1st jan of year y taking 1st jan of 1900 as monday. 
{
	int i;
	long d=0;
	for(i=1900;i<y;i++)     //calculating no of days for 1st jan 2016 after 1st jan 1900
		d+=365+isleap(i);
	return ((d%7+1)%7);		//1 means monday.
}
int dowjan1before(int y)//returns day of week no for 1st jan of year y taking 1st jan of 1900 as monday. 
{
	int i;
	long d=0;
	for(i=1900;i>y;i--)     //calculating no of days for 1st jan 2016 after 1st jan 1900
		d+=365+isleap(i);
	return ((d%7)-1)%7;		//1 means monday.
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
void showcal(int mno,int year)
{
	char m[][100]={"January","February","March","April","May","June","July","August","September","October","November","December"};
	char z[][200]={"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
	int a[]={31,28,31,30,31,30,31,31,30,31,30,31};
	int i,jan1,s=0,u,j,l=1,k=3;
	
	
	if(isleap(year)==1)
		a[1]=29;
	if(year>=1900)	
		jan1=dowjan1after(year);
	else
		jan1=dowjan1before(year);
	for(i=0;i<(mno-1);i++)
	s+=a[i];		
	u=(jan1+(s%7))%7;
	clrscr();
	drawbox();
	gotoxy(2,2);
	printf("%13s`%d AD\n",m[mno-1],year);
	gotoxy(1,3);
	printf("%c",199);
	for(i=1;i<29;i++)
		printf("%c",205);
	printf("%c",182);
	gotoxy(5,3);
	printf("%c",209);
	
	gotoxy(2,4);
	for(i=0;i<7;i++)
		printf("%s ",z[i]);	
	gotoxy(1,5);
	printf("%c",199);
	for(i=1;i<29;i++)
		printf("%c",196);
	printf("%c",182);	
	gotoxy(2,6);
		for(j=0;j<=u;j++)
		{
			if(j==u)
			{
				
				printf("%*d",k,1);
				k+=4;
				for(i=2;i<=a[mno-1];i++)
					{
						if(k>27)
						{
							printf("\n");
							k=3;
							gotoxy(2,6+l);
							l++;
							printf("%3d",i);
							k+=4;
						}
						else
						{
							printf("%4d",i);
							k+=4;
						}
					}
				break;	
    		}	
    		else
			k+=4;
		}
}

int main()
{
	char m[][100]={"January","February","March","April","May","June","July","August","September","October","November","December"};
	
	int year,mno,i,ch;
	char month[200];
	printf("enter year:-\n");
	scanf("%d",&year);
	printf("enter month:-\n");
	fflush(stdin);
	gets(month);
/*	printf("enter day of 1st Jan %d:-",year);
	gets(day);*/
	for(i=0;i<12;i++)
		if(strcmpi(m[i],month)==0)
		{
			mno=i+1;
			break;
		}
	if(i==12)
	{	
		printf("invalid input");
	}
	do    //escape=27
	{
		showcal(mno,year);
		ch=getch();
		switch(ch)
		{
			case 's':
			case 'S':
		/*	if(year>1900)*/
			year--;
			break;
			
			case 'a':
			case 'A':
			mno--;
			if(mno<1)
			{
				mno=12;
				year--;
			/*	if(year<1900)
				{
					year=1900;
					mno=1;
				}*/
			}
			break;
			
			case 'w':
			case 'W':
			year++;	
			break;
			
			case 'd':
			case 'D':
			mno++;
			if(mno>12)
			{
				mno=1;
				year++;
			}	
			break;
					
		}	
	}while(ch!=27);
	
}

