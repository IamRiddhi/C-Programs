#include<stdio.h>
#include<stdlib.h>
typedef struct ThBinTree
{
	int data;
	struct ThBinTree *left;
	struct ThBinTree *right;
	int lthrd;
	int rthrd;
}ThBinTree;
ThBinTree* CreateThBinTree(int d)
{
	ThBinTree *t;
	t=(ThBinTree*)malloc(sizeof(ThBinTree));
	t->data=d;
	t->left=NULL;
	t->right=NULL;
	t->lthrd=1;
	t->rthrd=1;
}

int main()
{

	getch();
}
