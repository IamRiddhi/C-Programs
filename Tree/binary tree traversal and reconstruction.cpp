#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#define gapsx 2
#define gapsy 2

#define A 1
#define B 2
#define C 3
#define D 4
#define E 5
#define F 6
#define G 7
#define H 8
#define I 9
#define J 10


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
void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}
typedef struct btree
{
	int data;
	struct btree *right;
	struct btree *left;
}btree;
btree* createbinarytree(int d)
{
	btree *t;
	t=(btree*)malloc(sizeof(btree));
	t->data=d;
	t->left=t->right=NULL;
	return t;
}
void setleft(btree *t,int d)
{
	t->left=createbinarytree(d);
}
void setright(btree *t,int d)
{
	t->right=createbinarytree(d);
}
void preorder(btree  *t)
{
	if(t!=NULL)
	{
		printf("%c\n",'A'+t->data-1);
		preorder(t->left);
		preorder(t->right);
	}
}
void inorder(btree *t)
{
	if(t!=NULL)
	{
		inorder(t->left);
		printf("%c\n",'A'+t->data-1);
		inorder(t->right);
	}
}
void postorder(btree *t)
{
	if(t!=NULL)
	{
		postorder(t->left);
		postorder(t->right);
		printf("%c\n",'A'+t->data-1);
	}
}
/*int count(btree *t,int k,int *rsub)
{
	int c=0,m=0;
	btree *t1;
	if(k==0 && t->left!=NULL)
			{t=t->left;
			m=1;}   //0->left.
	else if(k==1 && t->right!=NULL)
		{	t=t->right;
		m=1;}	//1->right.
		*t1=t;
	while(t!=NULL && m!=0)
	{
		if(k==0)
			t=t->left;   //0->left.
		else if(k==1)
			t=t->right;	//1->right.
		c++;
	if(t==NULL)
			m=0;
	}
	while(t1!=NULL && m!=0)
	{
			if(k==0)
			t=t->right;   //0->left.
		else if(k==1)
			t=t->left;	//1->right.
		*rsub++;
	if(t==NULL)
			m=0;
	}
		return c; //same case
}*/
btree* reconprein(int pre[],int in[],int n)
{
	int i;
	btree *t;
	if(n==NULL)
	 return NULL;
 	for(i=0;i<n;i++)
 		if(in[i]==pre[0])
 			break;
	t=createbinarytree(pre[0]);
	t->left=reconprein(pre+1,in,i);
	t->right=reconprein(pre+i+1,in+i+1,n-i-1);
	return t;			
}
btree* reconpostin(int post[],int in[],int n)
{
	int i;
	btree *t;
	if(n==0)
		return NULL;
	for(i=0;i<n;i++)
		if(in[i]==post[n-1])
			break;	
	t=createbinarytree(post[n-1]);
	t->left=reconpostin(post,in,i);
	t->right=reconpostin(post+i,in+i+1,n-i-1);
	return t;	
}
int leftsubtree(btree *t)
{
	if(t==NULL)
		return 0;	
	return (1+leftsubtree(t->left))+(leftsubtree(t->right));
	
}
/*int Drawbintree(btree *t,int *w,int *h)
{
	int i,j,leftsub,rightsub;
	if(t==NULL)
	{
		*w=0;
		*h=1;
		return 0;
	}
	gotoxy(Drawbintree(t->left,w,h),*h);
	printf("%c",t->data);
	Drawbintree(t->right,w,h);
		return *w+
		

}*/
int main()
{
	 CONSOLE_SCREEN_BUFFER_INFO csbi;
    int c, r;
	ShowConsoleCursor(true);
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    c = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    r= csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	btree *t;
	int w,h;
//	t=createbinarytree(65);
/*	setleft(t,66);
	setright(t,67);
	setleft(t->left,68);
	setright(t->left,69);
	setleft(t->left->right,71);
	setright(t->left->right->left,74);
	setleft(t->right,70);
	setleft(t->right->left,72);
	setright(t->right->left,73);
	printf("%d",leftsubtree(t->left));*/
//	preorder(t);
//	inorder(t);
	//postorder(t);*/
	//Drawbintree(t,&w,&h);
///	int post[]={4,10,1,5,2,8,9,6,3,1};
//	int in[]={4,2,7,10,5,1,8,6,9,3};
	int post[]={D,J,G,E,B,H,I,F,C,A};
	int in[]={D,B,G,J,E,A,H,F,I,C};
	t=reconpostin(post,in,sizeof(post)/sizeof(post[0]));
	preorder(t);
//	postorder(t);
//inorder(t);
	getch();
}
