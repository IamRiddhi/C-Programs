#include<stdio.h>
#include<malloc.h>
#include<string.h>
int main()
{
	char **n;
	char t[100];
	int i,name;
	printf("how many names?");
	scanf("%d",&name);
	n=(char**)malloc(name*sizeof(char*));
	for(i=0;i<name;i++)
	{
		printf("enter name:");
		fflush(stdin);
		gets(t);
		n[i]=(char*)malloc((strlen(t)+1)*sizeof(char));
		strcpy(n[i],t);
	}
	for(i=0;i<name;i++)
	{
		puts(n[i]);
		free(n[i]);
	}
	free(n);
		
}
