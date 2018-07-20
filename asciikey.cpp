#include <stdio.h>
#include <conio.h>

int getKey(void)
{
    int ch = getch();
    if (ch == 0 || ch == 224)
        ch = 500 + getch();
    return ch;
}

int main(void)
{
	int ch ;

	
	puts("Press any key to see its code. ESC to exit") ;
	
	do
	{
		ch = getKey() ;
	    printf("You pressed key with code %d\n", ch) ;
	} while(ch != 27) ;
	
    
    return 0 ;
}
