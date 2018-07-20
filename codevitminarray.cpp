#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int lowest(int *a,int n)
{
	int i,l;
	l=a[0];
	for(i=1;i<n;i++)
	{
		if(a[i]<l)
			l=a[i];
	}
	return l;
}
int main()
{
	int n,k,i,j,*a,*b,*s,x,m=0, t;
	printf("enter the size of the arrays:");
	scanf("%d",&n);
	printf("\nenter how many modifications are allowed:");
	scanf("%d",&k);
	a=(int*)malloc(n*sizeof(int));
	b=(int*)malloc(n*sizeof(int));
	x=2*n;
	s=(int*)calloc(x, sizeof(int));
	printf("\nenter the values of modifiable array:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
		printf("\n\nenter the values of unmodifiable array:");
		for(i=0;i<n;i++)
	{
	 	scanf("%d",&b[i]);
	}
	for(i=0;i<n;i++)
	{
		t=a[i];
		a[i]+=k*2;
		for(j=0;j<n;j++)
			s[m]+=(a[j]*b[j]);
		m++;
		a[i]=t;
		a[i]-=k*2;
		for(j=0;j<n;j++)
			s[m]+=(a[j]*b[j]);
		m++;	
		a[i]=t;		
	}

	printf("\nthe required output is %d",lowest(s,m-1));
	
}
