#include<stdio.h>
#include<malloc.h>
int main()
{
	int 	**a,n,t,i,j,f,l,temp;
	printf("enter the dimension of square matrix:");
	scanf("%d",&n);
	a=(int**)malloc(n*sizeof(int*));
	for(i=0;i<n;i++)
		a[i]=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			printf("enter element in %d row and %d column:",(i+1),(j+1));
			scanf("%d",&a[i][j]);
		}
			printf("The original matrix is:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d\t",a[i][j]);
		printf("\n");		
	}
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
		{
			t=a[i][j];
			a[i][j]=a[j][i];
			a[j][i]=t;
		}	
	for(i=0;i<n;i++)
	{
		f=0;
		l=n-1;
		while(f<l)
		{
			temp=a[i][f];
			a[i][f]=a[i][l];
			a[i][l]=temp;
			f++;
			l--;
		}
		
	}
	
	printf("The matrix after rotation of 90 degrees:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d\t",a[i][j]);
		printf("\n");		
	}
}
