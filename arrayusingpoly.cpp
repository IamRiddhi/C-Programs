#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
typedef struct
{
	int exp;
	int coef;
}elem;
typedef struct
{
	elem *a;
	int n;
}poly;
void initpoly(poly *p,int n)
{
	p->n=n;
	p->a=(elem*)malloc(p->n*sizeof(elem));
}
void sortpoly(poly *p)
{
	int j,i;
	elem t;
	for(i=p->n-1;i>0;i--)
	{
		for(j=0;j<i;j++)
		{
			if(p->a[j].exp>p->a[j+1].exp)
			{
				t=p->a[j];
				p->a[j]=p->a[j+1];
				p->a[j+1]=t;	
			}
		}
	}
}
void createpoly(poly *p)
{
	int i;
	for(i=0;i<p->n;i++)
	{
		printf("\nENTER COEFFIECNT OF ELEMENT %d:",i+1);
		scanf("%d",&p->a[i].coef);
		printf("\nENTER EXPONENT OF ELEMENT %d:",i+1);
		scanf("%d",&p->a[i].exp);
	}
	
}
void printpoly(poly *p)
{
	int i,e,c,j=0;
	for(i=0;i<p->n;i++)
	{
		c=p->a[i].coef;
		e=p->a[i].exp;
		if(j>0 && c>0)
			printf("+");
			
		if(c!=1 && c!=0 && c!=-1)
		{
			printf("%d",c);
			
		}
		if(c==-1)
			printf("-");
		if(c!=0)
			j++;	
		if(e!=0 && c!=0)
		{
			printf("x");
			if(e!=1)
				printf("^%d",p->a[i].exp);
		}		
		 if(c==1 && e==0 || c==-1 && e==0)
		 	printf("1");
			 	
	}
}
float evaluate(poly *p,float x)
{
	float s=0;
	int i;
	for(i=0;i<p->n;i++)
	{
		s+=p->a[i].coef*pow(x,p->a[i].exp);
	}
	return s;
}
void addpoly(poly *p,poly *q,poly *r)
{
	int i=0,k=0,j=0;
			r->n=p->n+q->n;
			r->a=(elem*)malloc(r->n*sizeof(elem));
		
	while(i<p->n && j<q->n )
	{
		if(p->a[i].exp==q->a[j].exp)
		{
			r->a[k]=p->a[i++];
			r->a[k++].coef+=q->a[j++].coef;
		}
		else if(p->a[i].exp<q->a[j].exp)
		{
			r->a[k++]=p->a[i++];
		}
		else
			r->a[k++]=q->a[j++];

	}
	while(i<p->n)
		r->a[k++]=p->a[i++];
	while(j<q->n)
		r->a[k++]=q->a[j++];
	r->n=k;		
}
int main()
{
	poly p,q,r;
	float x;
	int n1,n2,ch;
	while(1)
	{
		printf("\n1.Create Polynomial Expression\n2.Print Polynomial Expression\n3.Evaluate Expression\n4.Add Polynomial Expression\n6.Exit\n\n");
		printf("ENTER CHOICE:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:   printf("\nHOW MANY TERMS IN THE EXPRESSION 1?:");
					scanf("%d",&n1);
					printf("\nHOW MANY TERMS IN THE EXPRESSION 2?:");
					scanf("%d",&n2);
					printf("\nCREATING POLYNOMIAL EXPRESSION 1:\n");
						initpoly(&p,n1);
						createpoly(&p);
						sortpoly(&p);
					printf("\nCREATING POLYNOMIAL EXPRESSION 2:\n");
						initpoly(&q,n2);
						createpoly(&q);
						sortpoly(&q);
					break;
			case 2:   printf("\nTHE POLYNOMIAL EXPRESSIONS ARE \n");
					printpoly(&p);
					printf("\n\n");
					printpoly(&q);
					break;	
			case 3:	printf("\nENTER THE VALUE OF \'x\':");
					scanf("%f",&x);
					printf("\nTHE RESULT IS %3.2f OF EXPREESION 1 AND %3.2f OF EXPRESSION 2\n\n",evaluate(&p,x),evaluate(&q,x));	
					break;
			case 4:	addpoly(&p,&q,&r);
					printf("\n\nTHE SUMMATION IS ");
					printpoly(&r);	
			case 6:   exit(1);		
		}
	}
}
