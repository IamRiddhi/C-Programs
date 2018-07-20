#include<stdio.h>
#include<stdlib.h>
int common(int *a,int *b,int *c,int na,int nb)
{
	int i,j,k=0;
	
	for(i=0;i<na;i++)
	{
		for(j=0;j<nb;j++)
		{
			if(a[i]==b[j])
				c[k++]=a[i];
		}
	}
	
	return k;
}
int main()
{
	int a[100],b[100],c[100],i,na=0,nb=0,k,u,l,m,n,h,t;
	printf("enter lower and upper limits:");
	scanf("%d%d",&l,&u);
	if(l<1 || u>99999)
	{
		printf("invalid input");
		exit(1);
	}
	printf("enter the value of m:");
	scanf("%d",&m);
	n=1;
	while(1)
	{
		h=n*(2*n-1);
		if(h>=l && h<u)
		{
			a[na++]=h;
			n++;
		}
		else if(h>u)
			break;
		else		
			n++;				
	}
	n=1;
	while(1)
	{
		t=n*(n+1)/2;
		if(t>u)
			break;
		if(t>=l)
			b[nb++]=t;
		n++;		
	}
	k=common(a,b,c,na,nb);
	printf("\n");
	m-=1;
	if(m>=0 && m<k)
		printf("the required output is %d ",c[m]);
	else	
		printf("No number present in this index");
}
