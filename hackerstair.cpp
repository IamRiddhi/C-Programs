#include<stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int  i,j,k,m=0,c,**a,*t;
	scanf("%d",&k);
	a=(int**)malloc(k*sizeof(int*));
	t=(int*)malloc(k*k*sizeof(int));
	for(i=0;i<k;i++)
	{
		a[i]=(int*)malloc(k*sizeof(int));
	}
	for(i=0;i<k;i++)
	{
		for(j=0;j<k;j++)
		{
			printf("enter element in %d row and %d col",i+1,j+1);
			scanf("%d",&a[i][j]);
		}
	}
	 
}
