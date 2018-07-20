#include<stdio.h>
int currentdigit(int n,int pos) //pos counted from end.
{
	int x=0;
	while(x<pos-1)
	{
		n=n/10;
		x++;
	}
	n=n%10;
	return n;
}
int reverse(int n)
{
	int p=0,r;
	if(n>=1 && n<10)
	{
		return n*10;
	}
	while(n!=0)
	{
		r=n%10;
		n/=10;
		p=p*10+r;
	}
	return p;
}
int foldreverse(int key)
{
	int i,a=0,b=0,d;
	for(i=1;i<=4;i++)
	{
		d=currentdigit(key,i);
		if(i<3)
			b=b*10+d;
		else
			a=a*10+d;	
	}
	a=reverse(a);
	a+=b;
	b=0;
	for(i=0;i<2;i++)
	{
		
		b=b*10+currentdigit(a,1+i);
	}
	b=reverse(b);
	return b;
}
int main()
{
	int k;
	printf("enter the key value:");
	scanf("%d",&k);
	printf("%d",foldreverse(k));
}
