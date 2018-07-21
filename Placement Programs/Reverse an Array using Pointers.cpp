/*Reverse an array using pointers*/
#include<stdio.h>
#include<stdlib.h>
int main(int argc,char **argv)
{
	int n = argc - 1;
	int i;
	int *f,*l;
	int temp;
	int *a = new int[n];
	for(i=1;i<argc;i++)
		a[i-1] = atoi(argv[i]);
	
	printf("Array before reversing: ");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n Array after reversing: ");
	
	f = a;
	l = a+n-1;
	
	while(f<l)
	{
		temp = *f;
		*f = *l;
		*l = temp;
		f++;
		l--;	
	}
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}
