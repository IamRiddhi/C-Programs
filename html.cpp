#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
	int roll;
	char name[50];
	int phy;
	int math;
	int cse;
	int total;
}stu;
int main()
{
	int n,i;
	char *red="red", *blue="blue";
	stu s;
	FILE *fp;
	fp=fopen("c:\\users\\lenovo\\desktop\\pr.html","w");
	fprintf(fp,"<!DOCTYPE=html>\n<html>\n<head>\n<title>html1.c</title>\n<style>\ntable, th, td {\nborder: 1px solid black;\nborder-collapse: collapse;background-color:yellow;\n}\nth, td {\npadding: 5px;\n}\n</style>\n</head>\n<body>\n<table style=\"width:100%%\">\n<caption style=\"color:red\"><b><h1>Markheet Table</h1></b></caption>\n<tr>\n<b>\n<h2>\n<th rowspan=\"2\">Roll</th>\n<th rowspan=\"2\">Name</th>\n<th colspan=\"3\">Marks</th>\n<th rowspan=\"2\">Total</th>\n<th rowspan=\"2\">Average</th>\n</tr>\n<tr>\n<td><i>Maths</i></td>\n<td><i>Physics</i></td>\n<td><i>Computer</i>\n</tr>\n</b>\n</h2>\n");
	printf("how many students?:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("enter student name:");
		fflush(stdin);
		gets(s.name);
		printf("enter roll:");
		scanf("%d",&s.roll);
		printf("enter marks in physics:");
		scanf("%d",&s.phy);
		printf("enter marks in computer:");
		scanf("%d",&s.cse);
		printf("enter marks in maths:");
		scanf("%d",&s.math);	
		s.total=s.math+s.phy+s.cse;
		fprintf(fp,"<tr>\n<td>%d</td>\n<td>%s</td>\n",s.roll,s.name);

		fprintf(fp,"<td style=\"color:%s\">%d</td>\n",s.math>=50? blue:red, s.math);
		fprintf(fp,"<td style=\"color:%s\">%d</td>\n",s.phy>=50? blue:red, s.phy);
		fprintf(fp,"<td style=\"color:%s\">%d</td>\n",s.cse>=50? blue:red, s.cse);
	
		fprintf(fp,"<td>%d</td>\n<td>%6.2f</td>\n</tr>\n",s.total,(s.total/3.0));		
	}
	fprintf(fp,"</table>\n</body>\n</html>");
	fclose(fp);
}

