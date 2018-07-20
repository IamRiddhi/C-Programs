#include<stdio.h>
int prime(int n)
{
	int i,c=0;
	for(i=2;i<n/2;i++)
	{
		if(n%i==0)
		{
			c++;
			break;
		}
	}
	if (c==0)
		return 1;
	else
		return 0;	
}
int main()
{
	/*int x,n,i,p,j,t;
	printf("enter the value of i:");
	scanf("%d",&i);
	printf("enter the value of n:");
	scanf("%d",&n);
/*	for(p=2;p<=n;p++)
	{
		if(!prime(p))
			continue;
		t=p;
		for(j=0;j<i;j++)
		{
			t=2*t+1;
			if(!prime(t))
				break;
		}
		if(j==i)
			printf("%d\n",p);
	}
	*/
	printf("%d",prime(4));

}
