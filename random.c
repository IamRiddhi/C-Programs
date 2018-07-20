#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main()
{
	int i;
	time_t t;
	srand(time(&t));
	for(i=0;i<10;i++)
		printf("%d\n",rand() % 100 );
	return 0;		
}
