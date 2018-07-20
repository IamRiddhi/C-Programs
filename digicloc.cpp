#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
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
int colon(int x,int y)
{
	int i;
	gotoxy(x,y);
	printf("%c",178);
	gotoxy(x,y+7);
	printf("%c",178);
	return wherex();
}
int zero(int x,int y)
{
	int i,cx,cy;
	for(i=0;i<11;i++)
	{
			if(i==5)
		{
			gotoxy(x+i,y);
			printf("%c",223);
			continue;
		}
		gotoxy(x+i,y);
		printf("%c",219);
	}
	cx=wherex();
	for(i=0;i<11;i++)
	{
			if(i==5)
		{
			gotoxy(cx,y+i+1);
			printf("%c",222);
			continue;
		}
		gotoxy(cx,y+i+1);
		printf("%c",219);
	}
	cy=wherey();
	for(i=0;i<11;i++)
	{
		
			if(i==5)
		{
			gotoxy(x+i,cy+1);
			printf("%c",220);
			continue;
		}
		gotoxy(x+i,cy+1);
		printf("%c",219);
	}
	for(i=0;i<11;i++)
	{
			if(i==5)
		{
			gotoxy(x-1,y+i+1);
			printf("%c",221);
			continue;
		}
		gotoxy(x-1,y+i+1);
		printf("%c",219);
	}
	return wherex();
//	gotoxy(x,y);
	
}
int one(int x,int y)
{
	int i;
	for(i=0;i<13;i++)
	{
		if(i==6)
		{
			gotoxy(x,y+i);
			printf("%c",222);
			continue;
		}
		gotoxy(x,y+i);
			printf("%c",219);
	}
	return wherex();
	
}
int two(int x,int y)
{
	int i,cy;
		for(i=0;i<10;i++)
	{
		gotoxy(x+i,y);
			printf("%c",219);
	}

	for(i=0;i<5;i++)
	{
		gotoxy(x+10,y+1+i);
		printf("%c",219);
	}
	gotoxy(x+10,y+1+i);

	cy=wherey();
	gotoxy(x,cy);
	for(i=0;i<10;i++)
	{
		gotoxy(x+i,cy);
			printf("%c",219);
	}
	gotoxy(x,cy);

	for(i=0;i<5;i++)
	{
			gotoxy(x-1,cy+1+i);
			printf("%c",219);
	}
	gotoxy(x,wherey()+1);

	cy=wherey();
	for(i=0;i<10;i++)
	{
		gotoxy(x+i,cy);
			printf("%c",219);
	}
	return wherex();
}
int three(int x,int y)
{
	int i,cx,cy;
		for(i=0;i<10;i++) //first head
	{
		gotoxy(x+i,y);
			printf("%c",219);
	}

	for(i=0;i<5;i++)  //first vertical.
	{
		gotoxy(x+10,y+1+i);
		printf("%c",219);
	}
	gotoxy(x+10,y+1+i);

	cy=wherey();
	gotoxy(x,cy);
	for(i=0;i<10;i++)      //second head.
	{
		gotoxy(x+i,cy);
			printf("%c",219);
	}
	
	cy=wherey()+1;
	cx=wherex();
	for(i=0;i<5;i++)    //second vertical.
	{
		gotoxy(cx,cy+i);
		printf("%c",219);
	}
	cx-=10;
	cy+=5;
	for(i=0;i<10;i++)
	{
		gotoxy(cx+i,cy);
		printf("%c",219);
	}
	return wherex();
}

int four(int x,int y)
{
	int i,cy,cx;
	for(i=0;i<7;i++)
	{
		gotoxy(x,y+i);
		printf("%c",219);
	}
	cy=wherey();
	for(i=0;i<10;i++)
	{
		gotoxy(x+i+1,cy+1);
		printf("%c",219);
	}
	cx=wherex();
	for(i=0;i<5;i++)
	{
		gotoxy(cx,cy+i+2);
		printf("%c",219);
	}
	
	for(i=0;i<7;i++)
	{
		gotoxy(cx,y+i);
		printf("%c",219);
	}
	return wherex();
}
int five(int x,int y)
{
		int i,cy,cx;
		for(i=0;i<10;i++)
		{
			gotoxy(x+i,y);
			printf("%c",219);
		}
		for(i=0;i<5;i++)
		{
			gotoxy(x-1,y+i+1);
			printf("%c",219);
		}
		gotoxy(x+10,y+1+i);

	cy=wherey();
	gotoxy(x,cy);
	for(i=0;i<10;i++)
	{
		gotoxy(x+i,cy);
			printf("%c",219);
	}
	cx=wherex();
	for(i=0;i<5;i++)
	{
			gotoxy(cx,cy+i+1);
			printf("%c",219);
	}
	gotoxy(x,wherey()+1);

	cy=wherey();
	for(i=0;i<10;i++)
	{
		gotoxy(x+i,cy);
			printf("%c",219);
	}
	return wherex();
}
int six(int x,int y)
{
	int i,m,cy,cx;
		for(i=0;i<11;i++)
		{
			gotoxy(x+i,y);
			printf("%c",219);
		}
		for(i=0;i<5;i++)
		{
			gotoxy(x-1,y+i+1);
			printf("%c",219);
		}
		gotoxy(x+10,y+1+i);

	cy=wherey();
	gotoxy(x,cy);
	for(i=0;i<10;i++)
	{
		gotoxy(x+i,cy);
			printf("%c",219);
	}
	cx=wherex();
	m=wherey();
	for(i=0;i<5;i++)
	{
			gotoxy(cx,cy+i+1);
			printf("%c",219);
	}
	gotoxy(x,wherey()+1);

	cy=wherey();
	for(i=0;i<10;i++)
	{
		gotoxy(x+i,cy);
			printf("%c",219);
	}
	for(i=0;i<5;i++)
	{
		gotoxy(x-1,m+i+1);
			printf("%c",219);
	}
	return wherex();
}
int seven(int x,int y)
{
	int i,m,cy,cx;
		for(i=0;i<10;i++)
		{
			gotoxy(x+i,y);
			printf("%c",219);
		}
	one(wherex(),wherey());
	return wherex();
}
int eight(int x,int y)
{
	int i,m,cy,z,cx;
		for(i=0;i<10;i++)
		{
			gotoxy(x+i,y);
			printf("%c",219);
		}
		z=wherex();
		for(i=0;i<5;i++)
		{
			gotoxy(x-1,y+i+1);
			printf("%c",219);
		}
		gotoxy(x+10,y+1+i);

	cy=wherey();
//	z=cy;
	gotoxy(x,cy);
	for(i=0;i<10;i++)
	{
		gotoxy(x+i,cy);
			printf("%c",219);
	}
	cx=wherex();
	m=wherey();
	for(i=0;i<5;i++)
	{
			gotoxy(cx,cy+i+1);
			printf("%c",219);
	}
	gotoxy(x,wherey()+1);

	cy=wherey();
	for(i=0;i<10;i++)
	{
		gotoxy(x+i,cy);
			printf("%c",219);
	}
	for(i=0;i<5;i++)
	{
		gotoxy(x-1,m+i+1);
			printf("%c",219);
	}
	for(i=0;i<5;i++)
	{
		gotoxy(z,y+i+1);
			printf("%c",219);
	}
	return wherex();
}
int nine(int x,int y)
{
	int i,cx,cy;
	five(x,y);
	cx=wherex();
	for(i=0;i<5;i++)
	{
		gotoxy(cx,y+i+1);
		printf("%c",219);
	}
	return wherex();
}
int pm(int x,int y)
{
	int i,cy,cx;
	for(i=0;i<4;i++)
	{
		gotoxy(x,y+i);
			printf("%c",219);
	}
	cy=wherey();
	for(i=0;i<7;i++)
	{
		if(i==4)
		{
			gotoxy(x+i,y);
			printf("%c",220);
			continue;
		}
		gotoxy(x+i,y);
		printf("%c",219);
	}
	cx=wherex();
	for(i=0;i<4;i++)
	{
		gotoxy(cx,y+i);
		printf("%c",219);	
	}
	for(i=0;i<7;i++)
	{
		if(i==3)
		{
			gotoxy(x+i+1,cy+1);
			printf("%c",220);
			continue;
		}
		gotoxy(x+i+1,cy+1);
		printf("%c",219);
	}
	for(i=0;i<3;i++)
	{
		gotoxy(x,cy+i+2);
		printf("%c",219);
	}
	x+=11;
	y+=1;
	for(i=0;i<7;i++)
	{
		if(i==3)
		{
			gotoxy(x,y+i);
			printf("%c",222);
			continue;
		}
		gotoxy(x,y+i);
			printf("%c",219);
	}
	for(i=0;i<3;i++)
	{
		gotoxy(x+i+1,y-1);
		printf("%c",219);
	}
	cx=wherex();
	for(i=0;i<3;i++)
	{
		gotoxy(cx,y+i);
		printf("%c",219);
	}
	for(i=0;i<3;i++)
	{
		gotoxy(cx+i+1,y-1);
		printf("%c",219);
	}
	cx=wherex();
	for(i=0;i<7;i++)
	{
		if(i==3)
		{
			gotoxy(cx,y+i);
			printf("%c",222);
			continue;
		}
		gotoxy(cx,y+i);
			printf("%c",219);
	}
	return wherex();
}
int am(int x,int y)
{
	int i,cx,cy;
	for(i=0;i<6;i++)
	{
		gotoxy(x+i,y);
		printf("%c",219);
	}
	cx=wherex();
	for(i=0;i<3;i++)
	{
		gotoxy(cx,y+i+1);
		printf("%c",219);
	}
	for(i=0;i<3;i++)
	{
		gotoxy(x-1,y+i+1);
		printf("%c",219);
	}
	cy=wherey();
	for(i=0;i<6;i++)
	{
		gotoxy(x+i,cy+1);
		printf("%c",219);
	}
	cx=wherex();
	for(i=0;i<3;i++)
	{
		gotoxy(cx,cy+i+2);
		printf("%c",219);
	}
	for(i=0;i<3;i++)
	{
		gotoxy(x-1,cy+i+2);
		printf("%c",219);
	}
	x+=10;
	y+=1;
	for(i=0;i<7;i++)
	{
		if(i==3)
		{
			gotoxy(x,y+i);
			printf("%c",222);
			continue;
		}
		gotoxy(x,y+i);
			printf("%c",219);
	}
	for(i=0;i<3;i++)
	{
		gotoxy(x+i+1,y-1);
		printf("%c",219);
	}
	cx=wherex();
	for(i=0;i<3;i++)
	{
		gotoxy(cx,y+i);
		printf("%c",219);
	}
	for(i=0;i<3;i++)
	{
		gotoxy(cx+i+1,y-1);
		printf("%c",219);
	}
	cx=wherex();
	for(i=0;i<7;i++)
	{
		if(i==3)
		{
			gotoxy(cx,y+i);
			printf("%c",222);
			continue;
		}
		gotoxy(cx,y+i);
			printf("%c",219);
	}
	return wherex();
}

int min(int i,int ux)
{
	int cx;
	if(i>=0 && i<10)
	{
	 	cx=zero(ux,20);
		 i=currentdigit(i,1);
	 	if(i==0)
		{
			zero(cx+20,20);
		}
		else if(i==1)
		{
		
		one(cx+20,20);
		}
		else if(i==2)
		{
			two(cx+20,20);
		}
		else if(i==3)
		{
			three(cx+20,20);
		}
		else if(i==4)
		{	
			four(cx+20,20);
		}
		else if(i==5)
		{
			five(cx+20,20);
		}
		else if(i==6)
		{	
			six(cx+20,20);
		}
		else if(i==7)
		{
			seven(cx+17,20);
		}
		else if(i==8)
		{
			eight(cx+20,20);
		}
		else if(i==9)
		{
			nine(cx+20,20);
		}
	}
	else if(i>=10 && i<20)
	{
	 cx=one(ux,20);
	 i=currentdigit(i,1);
	 	if(i==0)
		{
			zero(cx+10,20);
		}
		else if(i==1)
		{
			one(cx+15,20);
		}
		else if(i==2)
		{
			two(cx+10,20);
		}
		else if(i==3)
		{
			three(cx+10,20);
		}
		else if(i==4)
		{	
			four(cx+10,20);
		}
		else if(i==5)
		{
			five(cx+10,20);
		}
		else if(i==6)
		{	
			six(cx+10,20);
		}
		else if(i==7)
		{
			seven(cx+10,20);
		}
		else if(i==8)
		{
			eight(cx+10,20);
		}
		else if(i==9)
		{
			nine(cx+10,20);
		}
	}
	else if(i>=20 && i<30)
	{
	 cx=two(ux,20);
	 i=currentdigit(i,1);
	 	if(i==0)
		{
			zero(cx+10,20);
		}
		else if(i==1)
		{
		
		one(cx+10,20);
		}
		else if(i==2)
		{
			two(cx+10,20);
		}
		else if(i==3)
		{
			three(cx+10,20);
		}
		else if(i==4)
		{	
			four(cx+10,20);
		}
		else if(i==5)
		{
			five(cx+10,20);
		}
		else if(i==6)
		{	
			six(cx+10,20);
		}
		else if(i==7)
		{
			seven(cx+10,20);
		}
		else if(i==8)
		{
			eight(cx+10,20);
		}
		else if(i==9)
		{
			nine(cx+10,20);
		}
	}
	else if(i>=30 && i<40)
	{
	 cx=three(ux,20);
	 i=currentdigit(i,1);
	 	if(i==0)
		{
			zero(cx+10,20);
		}
		else if(i==1)
		{
		
		one(cx+10,20);
		}
		else if(i==2)
		{
			two(cx+10,20);
		}
		else if(i==3)
		{
			three(cx+10,20);
		}
		else if(i==4)
		{	
			four(cx+10,20);
		}
		else if(i==5)
		{
			five(cx+10,20);
		}
		else if(i==6)
		{	
			six(cx+10,20);
		}
		else if(i==7)
		{
			seven(cx+10,20);
		}
		else if(i==8)
		{
			eight(cx+10,20);
		}
		else if(i==9)
		{
			nine(cx+10,20);
		}
	}
	else if(i>=40 && i<50)
	{
	 cx=four(ux,20);
	 i=currentdigit(i,1);
	 	if(i==0)
		{
			zero(cx+10,20);
		}
		else if(i==1)
		{
		
		one(cx+10,20);
		}
		else if(i==2)
		{
			two(cx+10,20);
		}
		else if(i==3)
		{
			three(cx+10,20);
		}
		else if(i==4)
		{	
			four(cx+10,20);
		}
		else if(i==5)
		{
			five(cx+10,20);
		}
		else if(i==6)
		{	
			six(cx+10,20);
		}
		else if(i==7)
		{
			seven(cx+10,20);
		}
		else if(i==8)
		{
			eight(cx+10,20);
		}
		else if(i==9)
		{
			nine(cx+10,20);
		}
	}
	else if(i>=50 && i<60)
	{
	 cx=five(ux,20);
		i=currentdigit(i,1);
			if(i==0)
		{
			zero(cx+10,20);
		}
		else if(i==1)
		{
		
		one(cx+10,20);
		}
		else if(i==2)
		{
			two(cx+10,20);
		}
		else if(i==3)
		{
			three(cx+10,20);
		}
		else if(i==4)
		{	
			four(cx+10,20);
		}
		else if(i==5)
		{
			five(cx+10,20);
		}
		else if(i==6)
		{	
			six(cx+10,20);
		}
		else if(i==7)
		{
			seven(cx+10,20);
		}
		else if(i==8)
		{
			eight(cx+10,20);
		}
		else if(i==9)
		{
			nine(cx+10,20);
		}
	}
	return wherex();
}
int hour(int x)
{
	int cx;
	if(x==0 || x==24)
	{
		cx=zero(5,20);
		zero(cx+20,20);
	}
	else if(x==1 || x==13)
	{
		cx=zero(5,20);
		one(cx+20,20);
	}
	else if(x==2 || x==14)
	{
		cx=zero(5,20);
		two(cx+20,20);
	}
	else if(x==3 || x==15)
	{
		cx=zero(5,20);
		three(cx+20,20);
	}
	else if(x==4 || x==16)
	{
		cx=zero(5,20);
		four(cx+15,20);
	}
	else if(x==5 || x==17)
	{
		cx=zero(5,20);
		five(cx+20,20);
	}
	else if(x==6 || x==18)
	{
		cx=zero(5,20);
		six(cx+20,20);
	}
	else if(x==7 || x==19)
	{
		cx=zero(5,20);
		seven(cx+17,20);
	}
	else if(x==8 || x==20)
	{
		cx=zero(5,20);
		eight(cx+20,20);
	}
	else if(x==9 || x==21)
	{
		cx=zero(5,20);
		nine(cx+20,20);
	}
	else if(x==10 || x==22)
	{
		cx=one(5,20);
		zero(cx+10,20);
	}
	else if(x==11 || x==23)
	{
		cx=one(5,20);
		one(cx+10,20);
	}
	else if(x==12)
	{
		cx=one(5,20);
		two(cx+10,20);
	}
	return wherex();									
}
int main()
{
	int i=0,x,y,z,cx,ux,zx;
	SYSTEMTIME st;
    char wks[][10] = {"SUN", "MON", "TUES","WEDNES", "THURS", "FRI", "SATUR"} ;
	char month[][50]={"JANUARY","FEBRUARY","MARCH","APRIL","MAY","JUNE","JULY","AUGUST","SEPTEMBER","OCTOBER","NOVEMBER","DECEMBER"};  
   // printf("The system time is: %02d:%02d:%02d of %02d/%02d/%4d, %sday", st.wHour, st.wMinute, st.wSecond, st.wDay, st.wMonth, st.wYear, wks[st.wDayOfWeek]);
    
	
    while(1)
    {
    		if(kbhit())
    			exit(2);
    		GetLocalTime(&st);
   	 	x=st.wHour;
    		y=st.wMinute;
    		z= st.wSecond;
    		i++;
    		clrscr();
    		gotoxy(70,10);
    		
  		  printf("%sDAY,%02d,%s,%04d",wks[st.wDayOfWeek],st.wDay,month[st.wMonth],st.wYear);
    		cx=hour(x);
    		if(x==0 || x==6 || x==10 || x==18 || x==22 || x==24)
    			ux=colon(cx+15,22);
    		else
    			ux=colon(cx+5,22);
    			if(x==0 || x==6 || x==10 || x==18 || x==22 || x==24)
    				zx=min(y,cx+20);
    			else
			    zx=min(y,cx+10);
		if(x>=12 && x<24)	    
			pm(130,22);
		else
			am(130,22);		    
		
    		if(i!=1)
    			Sleep(490);
    		if(y==0 || y==6 || y==10 || y==16 || y==20 || y==26 || y==30 || y==36 || y==40 || y==46 || y==50 || y==56)
    		{
				ux=colon(zx+15,22);
				
		}
    		else
    			{
				ux=colon(zx+5,22);
			}
    		zx=min(z,ux+10);//sec
    		Sleep(490);
    		
    	}
	getch();
}
