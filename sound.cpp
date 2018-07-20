#include<iostream.h>
#include<conio.h>
#include<dos.h>
void main()
{clrscr();  //for clearing the screen...
int x;
x=1000;         // here 1000 is the frequency of the sound 
sound(x);       //u can directly write integer in the place of x
delay(500);
nosound();      //it is necessary to close the sound or u will keep on hearing

getch();        // to wait at the end of program
}

