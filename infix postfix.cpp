#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
typedef struct
{
	int opr;
	char type;
}elem;
typedef struct
{
	int a[100];
	int top;
}stack;
int isfull(stack *sp)
{
	return (sp->top==99);
}
int isempty(stack *sp)
{
	return (sp->top==-1);
}
int peek(stack *sp)
{
	if(isempty(sp))
	{
		exit(1);
	}
	return sp->a[sp->top];
}
void push(stack *sp,int n)
{
	if(isfull(sp))  
		exit(2);
	sp->top++;
	sp->a[sp->top]=n;
}
int pop(stack *sp)
{
	if(isempty(sp))
		exit(1);
	return sp->a[sp->top--];		
}
int InPrec(char a)
{
	if(a=='*' || a=='/' || a=='%')
		return 2;
	else if(a=='+'|| a=='-')	
	 	return 1;
	 else if(a=='^')
	 	return 3;
	else if(a=='(')
		return 0;
	else
		printf("invalid operator\n");		 	
}
int OutPrec(char a)
{
	if(a=='*' || a=='/' || a=='%')
		return 2;
	else if(a=='+'|| a=='-')	
	 	return 1;
	 else if(a=='^')
	 	return 4;
	else if(a=='(')
		return 5;	
	else
		printf("invalid operator\n");		
}
int parse(char exp[],elem e[])
{
	int i,j=0,operand;
	char typ;
	for(i=0;exp[i]!='\0';i++)
	{
		if(exp[i]==' ')
			continue;
		
		if(isdigit(exp[i]))    //operand.
		{
			typ='D';		
			operand=0;
			while(isdigit(exp[i]))
			{
				operand=(operand*10)+(exp[i]-'0');
				i++;
			}
			i--;
			e[j].type=typ;
			e[j].opr=operand;
			
		}
		else
		{
			if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/' || exp[i]=='%' || exp[i]=='^' || exp[i]=='(')
				typ='R'; 				//opertor
			else /*if(exp[i]==')')*/
				typ=')';
		
			e[j].type=typ;
			e[j].opr=exp[i];	
		}
		j++;
	}
	return j;	
}
int InToPost(elem in[],int n,int post[])
{
	int i,j=0;
	stack s; //saves only the indices of the element array.
	s.top=-1;
	for(i=0;i<n;i++)
	{
		if(in[i].type==')')	// 2= )
		{
			while(in[peek(&s)].opr!='(')
			{
				post[j++]=pop(&s);
				
			}
			pop(&s);
		}
		else if(in[i].type=='D')
		{
			post[j++]=i;	
		}
		else     //operator
		{
			if(!isempty(&s) && InPrec(in[peek(&s)].opr)>=OutPrec(in[i].opr))
			{
				
				post[j++]=pop(&s);
			}
			push(&s,i);						
		}
	}
		while(!isempty(&s))
		{
			post[j++]=pop(&s);
		}
		return j;
}

void printelems(elem *e,int l)
{
	int i;
	for(i=0;i<l;i++)
	{
		printf(e[i].type=='D'?"%5d":"%5c",e[i].opr);
		printf(", %c\n", e[i].type);
	}
}
int evalpost(int post[],elem e[],int n)
{
	int i,x,y,r;
	stack s;
	s.top=-1;
	for(i=0;i<n;i++)
	{
		if(e[post[i]].type=='D')  		//operand
			push(&s,e[post[i]].opr);	
		else            // operator
		{
			y=pop(&s);
			x=pop(&s);
			if(e[post[i]].opr=='+')
				r=x+y;
			else if(e[post[i]].opr=='-')	
				r=x-y;
			else if(e[post[i]].opr=='*')	
				r=x*y;
			else if(e[post[i]].opr=='/')	
				r=x/y;
			else if(e[post[i]].opr=='^')	
				r=pow(x,y);	
			else 
				r=x%y;					
			push(&s,r);
		}	
	}
	r=pop(&s);
	return r;
}
int main()
{
	elem e[100];
	char a[100];
	int p[100];
	int i,l,lenp,c;		
	printf("enter expression:");
	gets(a);
	l=parse(a,e);
	lenp=InToPost(e,l,p);
	while(1)
	{
			printf("\n\n1.Convert Infix To Postfix\n2.Evaluate Expression.\n3.Exit\n");
			printf("\nenter choice:");
			scanf("%d",&c);
			switch(c)
			{
				case 1:	printf("\nThe corresponding postfix expression is ");
						for(i=0;i<lenp;i++)
						{
							printf(e[p[i]].type=='D'?"%d ":"%c ",e[p[i]].opr);
	
						}
						break;
				case 2:	printf("\nThe result is %d\n",evalpost(p,e,lenp));	
						break;
				case 3:   exit(1);		
			}
	}
}

