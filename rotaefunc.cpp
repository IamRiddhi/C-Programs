#include<stdio.h>
#include<malloc.h>
void rotate(int n,int **a)
{
	int t,f,l,i,j,temp;
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
}
void  print(int n,int **a)
{
	int i,j;
	printf("The matrix after rotation:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d\t",a[i][j]);
		printf("\n");		
	}
}
int main()
{
	int 	**a,n,an,i,j;
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
	printf("enter by how much angle you want to rotate?(90/180/270/360)");
	scanf("%d",&an);
	switch(an)
	{
		case 90:  rotate(n,a);
				print(n,a);
				break;
		case 180:for(i=0;i<2;i++)
					rotate(n,a);
				print(n,a);
				break;
		case 270:for(i=0;i<3;i++)
					rotate(n,a);
				print(n,a);
				break;
		case 360:for(i=0;i<4;i++)
					rotate(n,a);
				print(n,a);
				break;			
	}
}

