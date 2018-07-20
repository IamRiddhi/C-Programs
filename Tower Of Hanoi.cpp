#include<stdio.h>
void toh(char a,char c,char b,int n)
{
	if(n==1)
		printf("\n\nMOVE DISC FROM %c TO %c",a,c);
	else
	{	
		toh(a,b,c,n-1);
		printf("\n\nMOVE DISK FROM %c TO %c",a,c);
		toh(b,c,a,n-1);
	}	
}
int main()
{
	char a='A',b='B',c='C';
	int n;
	printf("ENTER NO OF DISKS:");
	scanf("%d",&n);
	toh(a,c,b,n);
}
