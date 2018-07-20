#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int countDigits(int k)
{
	int c=1;
	while(k/10!=0)
		++c;
	return c;
}
int bigAdd(char *a, char *b)
{
	int i,j;

}
int main()
{
	printf("%d\n",countDigits(231));
	printf("%d\n",countDigits(0));
    printf("%d",countDigits(23111));

}
