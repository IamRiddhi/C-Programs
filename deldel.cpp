#include<stdio.h>
#include<string.h>
int main()
{
	char a[100],b[100];
	int i,j,l;
	printf("/nenter main string:");
	gets(a);
	printf("/nenter string to delete:");
	gets(b);
	l=strlen(b);
	if(strlen(a)%l==0)
	{
		for(i=0;a[i]!='\0' && i<l;i++)
			if(strcmp(a[i],b[i]))
				break;
		
	}
	printf("\nNo");
}
