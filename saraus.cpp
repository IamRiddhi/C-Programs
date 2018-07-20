#include<stdio.h>
#include<malloc.h>
int diagonalelem1(int **a,int n,int *i1,int*j1)
{
	*i1=(++*i1)%n;
	*j1=(++*j1)%n;
	return a[*i1][*j1];
	
}
int diagonalelem2(int **a,int n,int *i1,int*j1)
{
	*i1=(++*i1)%n;
	*j1=(*j1-1);
	if(*j1<0)
		*j1=n-1;
	return a[*i1][*j1];
	
}

int sarrus(int **a,int n)	
{
	int i,j,k,m,t,l,i1,j1,d1=0,d2=0,c;
		for(j=0;j<n;j++)
		{
			i1=0;
			j1=j;
			l=a[i1][j];
			for(m=1;m<n;m++)
			{
			
				k=diagonalelem1(a,n,&i1,&j1);
				l*=k;
			
			}
			d1+=l;
		
		}
		j=n-1;
		for(c=1;c<=n;c++)
		{
			i1=0;
			j1=j;
			l=a[i1][j];
			for(m=1;m<n;m++)
			{
				
				k=diagonalelem2(a,n,&i1,&j1);
				l*=k;
			
			}
			d2+=l;
			j=(j+1)%n;
		}
	return d1-d2;
}
int main()
{
	int 	**a,n,i,j;
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
		printf("the result of determinant is %d",sarrus(a,n));
}

