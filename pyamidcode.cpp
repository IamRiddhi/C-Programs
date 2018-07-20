#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int countdigits(int n)
{
	int c=0;
	while(n!=0)
	{
		n=n/10;
		c++;
	}
	return c;
}
int main()
{
//	printf("%05d",23);
	int n,s=22,i,*x,f=0,j,t,y;
	printf("enter the width of the pyramid:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		f+=i;
//	printf("%d",f);	
	x=(int*)malloc(f*sizeof(int));
	for(i=0;i<f;i++)
	{
		x[i]=	8*( (i+1)*(i+1)-1 ) +7;
//		if(i==0)
//		{
//			x[i]=6;
//			t=x[i];
//		}
//		else
//		{
//			x[i]=t+s;
//			s+=16;
//			t=x[i];
//		}
	}
	y=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		{
			if(countdigits(x[y])<5)
				printf("%05d\t",x[y++]);
		else
			printf("%d\t",x[y++]);
		}
		printf("\n");
	}	
}
