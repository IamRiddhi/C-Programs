#include<stdio.h>
void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void permute(char a[],int n)
{
   int i;
   if (n == 1)
     printf("%c\n", a[0]);
   else
   {
       for (i = 0; i <n; i++)
       {
       	printf("%c",a[0]);
          permute(a+1, n-1);
          swap(&a[0], &a[n-1]);
		printf("\n"); 
       }
   }
}
int main()
{
	char a[3]={'A','B','C'};
	//printf("enter the value of n:");
	//scanf("%d",&n);
	
	permute(a,sizeof(a)/sizeof(a[0]));	
}
