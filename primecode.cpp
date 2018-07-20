#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int prime(int n)
{
	int i,c=0,j;
	for(j=2;j<=n/2;j++)
		{
			if(n%j==0)
			{
				c++;
				break;
			}
		}	
		return(c==0);
				
	
}
int main()
{
	int n,i,c=0,j,p[100],x=0,t,l;
	printf("enter the range:");
	scanf("%d",&n);
	for(i=3;i<=n;i+=2)
	{
		if(prime(i))
		{
			p[x++]=i;
		}
	}
	/*for(i=0;i<x;i++)
	printf("%d\n",p[i]);*/
	for(i=0;i<x;i++)
	{
		t=2;l=0;
		while(1)
		{
				t+=p[l++];
			if(p[i]==t)
			{
				printf("%d\n",p[i]);
				c++;
				break;
			}
			if(l>i || t>p[i])
				break;
		}
	}
	printf("\nthe required output is %d",c);
}
