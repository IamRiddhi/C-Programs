#include<stdio.h>
#include<stdlib.h>
int fact(int x)
{
	int f = 1,i;
	for(i=2;i<=x;i++)
		f *=i;
	return f;
}
int main(int argc,char **argv)
{
	int i,n;
	// argv[0] contains program name
	for(i=1;i<argc;i++)
		n = atoi(argv[i]);
	
	int temp = n;
	int sum = 0;
	while(temp>0)
	{
		int r = temp%10;
		sum += fact(r);
		temp /= 10;
	}
	if(sum==n)
		printf("yes");
	else
		printf("no");
	return 0;
}
