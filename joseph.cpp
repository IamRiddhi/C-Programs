#include<stdio.h>
#include<malloc.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>	
void clrscr(void)
{
   system("cls") ;	//clear screen.
}
int wherex()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&csbi);
	return csbi.dwCursorPosition.X;
}
int wherey()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&csbi);
	return csbi.dwCursorPosition.Y;
}
void gotoxy(short x, short y) 
{
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);		
}
typedef struct node
{
	char *data;
	struct node *next;
}node;
node* createnode(char *d)
{
	node *nd;
	nd=(node*)malloc(sizeof(node));
	nd->data=d;
	nd->next=NULL;
	return nd;
}
/*node* createlist(int data)
{
	int i;
	char data[100];
	node *first,*last,*nd;
	first=NULL;
	for(i=0;i<n;i++)
	{
		printf("enter your name:");
		fflush(stdin);
		gets(data);
		nd=	createnode(data);
		if(first==NULL)
			first=nd;
		else
			last->next=nd;
		last=nd;
	}
	last->next=first;
	return first;
}*/
/*void printlist(node *first)
{
	node *t=first;
	if(first!=NULL)
	{
		printf("%d\t",t->data);
		t=t->next;
	}
	while(t!=first)
	{
		printf("%d\t",t->data);
		t=t->next;
	 } 
}
void sirprint(node *first)
{
	node *t=first;
	if(t==NULL)
		return;
	do
	{
		printf("%d\t",t->data);
		t=t->next;
	}while(t!=first);	
}*/
void del(node **first,node *prev)
{
	node *node;
	node=prev->next;
	prev->next=node->next;
	if(node==*first)
		*first=node->next;
	free(node);	
}
char* josephus(char **a,int c,int p)
{
	int i;
	node *t,*first=NULL,*prev,*last,*nd;
	for(i=0;i<p;i++)
	{
		nd=createnode(a[i]);
		if(first==NULL)
			first=nd;
		else
			last->next=nd;
		last=nd;
	}
	last->next=first;
	t=first;
	if(t==NULL)   
	{
		printf("NULL LIST");
		exit(0);	
	}
	while(t->next!=t)
	{
		
		prev=t;
		for(i=1;i<c-1;i++)
		{
			prev=prev->next;
		
		}
		t=prev->next->next;
		del(&first,prev);
		
	}
	return t->data;
}
int main()
{
	int a,i,c;
	char **n;
	char ans[3],t[100];
	//node *start;
	while(1)
	{
		for(i=0;i<80;i++)
			printf("-");	
		gotoxy(25,2);	
		printf(" WELCOME TO JOSEPHUS COUNTING GAME\n\n");
		for(i=0;i<80;i++)
			printf("-");
		printf("HOW MANY PLAYERS?");
		scanf("%d",&a);
		//start=createlist(a);
		n=(char**)malloc(a*sizeof(char*));
		for(i=0;i<a;i++)
		{
			printf("\n\nENTER NAME:");
			fflush(stdin);
			gets(t);
			n[i]=(char*)malloc((strlen(t)+1)*sizeof(char));
			strcpy(n[i],t);
		}
		printf("\n\nHOW MANY COUNTS?");
		scanf("%d",&c);
		printf("\n\nTHE WINNER IS ");
		puts(josephus(n,c,a));
		printf("\n\nPRESS ANY KEY TO CONTINUE");
		getch();
			clrscr();	
			printf("PLAY AGAIN?");
			while(1)
			{
		
				fflush(stdin);
				gets(ans);
				if(strcmpi(ans,"no")==0 || strcmpi(ans,"yes")==0 )
			  		break;
				else
					printf("\n\nWRONG INPUT. ENTER AGAIN:-");
			}
			if(strcmpi(ans,"no")==0)
			  		break;
			else
			{
				clrscr();
				continue; 
			}

	}	
		clrscr();
		for(i=0;i<80;i++)
			printf("-");	
		gotoxy(25,2);	
		printf(" THANK YOU FOR PLAYING\n\n");
		for(i=0;i<80;i++)
			printf("-");
		printf("\n\nPRESS ANY KEY TO TERMINATE");
		getch();	
}
	
