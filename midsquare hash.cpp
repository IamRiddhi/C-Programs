#include<stdio.h>
#include<math.h>
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
int mid(int key)
{
	int c,d,hash=0,i;float f;
	key=pow(key,2);
	c=countdigits(key);
	f=c/2.0;
	c=f+0.999999;
	for(i=0;i<2;i++)
	{
		d=currentdigit(key,c-i);
		hash=hash*10+d;
	}
	return hash;
}
int main()
{
	int k;
	printf("enter the key value:");
	scanf("%d",&k);
	printf("%d",mid(k));
}
