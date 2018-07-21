#include<stdio.h>
#include<stdlib.h>
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void permute(int *a, int l, int r)
{
	int i;
	if(l==r)
	{
		for(i=0;i<=r;i++)
		{
			printf("%d",a[i]);
			i<(r)?printf(","):printf("\n");
		}
		return;
	}
	for(i=l;i<=r;i++)
	{
		swap(a+l,a+i);
		permute(a,l+1,r);
		swap(a+l,a+i);
	}
}
int main(int argc,char **argv)
{
	int size = argc - 1;
	int *a = new int[size];
	int i;
	for(i=1;i<argc;i++)
		a[i-1] = atoi(argv[i]);
	
	printf("The combinations of ");
	for(i=0;i<size;i++)
	{
		printf("%d",a[i]);
		if(i<size-1)
			printf(",");
		else 
			printf(" are as follows: \n");
	}
	
	permute(a,0,size-1);
	
}
