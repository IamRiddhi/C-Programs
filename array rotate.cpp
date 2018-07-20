#include <stdio.h>

#include<stdlib.h>

int main()

{

    int t,n,k,i,j,*a,temp1,temp2,m,l;
	printf("enter no of test cases");
    scanf("%d",&t);

    for(i=0;i<t;i++)

    {
	printf("enter size:");
    	scanf("%d",&n);
	printf("enter no of times you want to rotate:");
    	scanf("%d",&k);

    	a=(int*)malloc(n*sizeof(int));

    	for(j=0;j<n;j++)

    	scanf("%d",&a[j]);

    	for(j=0;j<k;j++)

    	{
         m=0;
    	temp2=a[m];

    	for(m=0;m<n;m++)

    	{

    	temp1=a[(m+1)%n];

    	a[(m+1)%n]=temp2;

    	temp2=temp1;

    	}

    	}

    	for(j=0;j<n;j++)

    	printf("%d\t",a[j]);

    

    }

    return 0;

}
