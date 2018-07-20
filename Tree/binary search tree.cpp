#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>


#define  MAXDGTS 2        /* Max number of digits in a key (for printing purpose) */
#define  GAPS MAXDGTS     /* Printed width of each key */

typedef struct bst
{
	int key;
	struct bst *right;
	struct bst *left;
}BST;
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
BST* search_key_iterative(BST *t, int k)
{
	while(t!=NULL && t->key==k)
	{
		if(k>t->key)
			t=t->right;
		else
			t=t->left;
	}
	return t;
}
BST* search_key_recursive(BST *t,int k)
{
	if(t==NULL || t->key==k)
		return t;
	if(k>t->key)
		return search_key_recursive(t->right,k);
	else
		return search_key_recursive(t->left,k);
}
BST* create_bst(int k)
{
	BST *t;
	t=(BST*)malloc(sizeof(BST));
	t->left=t->right=NULL;
	t->key=k;
	return t;
}
void insert_key_iterative(BST **x, int k)
{
	BST *t;
	if(*x==NULL)
	{
		*x=create_bst(k);
	}
	else
	{
		t=*x;
		while(t!=NULL)
		{
		 	if(t->key==k)
		 		break;
		 	if(k>t->key) //right
		 	{
		 		if(t->right==NULL)
				 {
				 	t->right=create_bst(k);
				 	break;
				 }
				 t=t->right;
			}
			else    //left
			{
				if(t->left==NULL)
				{
					t->left=create_bst(k);
					break;
				}
				t=t->left;
			}
		}
	}
}
void preorder(BST *t)
{
	if(t!=NULL)
	{
		printf("%d\t  ",t->key);
		preorder(t->left);
		preorder(t->right);
	}
}
void inorder(BST *t)
{
	if(t!=NULL)
	{
		inorder(t->left);
		printf("%d\t",t->key);
		inorder(t->right);
	}
}
void postorder(BST *t)
{
	if(t!=NULL)
	{
		postorder(t->left);
		postorder(t->right);
		printf("%d\t",t->key);
	}
}
BST *getMinNode(BST *t)
{
	if(t != NULL)
		while(t->left != NULL)
			t = t->left ;
    return t ;
}
BST *getMaxNode(BST *t)
{
	if(t != NULL)
		while(t->right != NULL)
			t = t->right ;
	return t ;
}
int countNodes(BST *root)
{
	if(root == NULL)
		return 0 ;
	else
		return countNodes(root->left) + 1 + countNodes(root->right) ;
}
int getHeight(BST *t)
{
    int l,r;
    if(t==NULL)
        return 0;
    l=getHeight(t->left);
    r=getHeight(t->right);
    return 1+ (l>r?l:r);
}
void deleteBST(BST *t)
{
    if(t==NULL)
        return ;
     deleteBST(t->left);
     deleteBST(t->right);
     free(t);
}
void MirrorTree(BST *t)
{

    BST *t1;
    if(t==NULL)
        return ;
    MirrorTree(t->left);
    MirrorTree(t->right);
    t1=t->right;
    t->right=t->left;
    t->left=t1;
}
void delKey(BST **t,int k)
{
    BST *p=NULL,*n=*t,*s;
    if(*t==NULL)
        return ;
    else
    {
        while(n!=NULL)
        {
            if(n->key==k)
                break;
            p=n;
            if(k>n->key)
                n=n->right;
            else
                n=n->left;
        }
        if(n==NULL)
        {
            printf("\nKey not found.\n");
            return;
            }
        if(n->left!=NULL && n->right!=NULL)
        {
            p=n;
            s=n->right;
            while(s->left!=NULL)
            {
                p=s;
                s=s->left;
            }

            n->key=s->key;
            n=s;
        }
        if(p==NULL)
        {

            if(n->left!=NULL)
                *t=n->left;
            else
                *t=n->right;
            free(n);
            return;
        }
        if(n==p->left)
        {
            if(n->left!=NULL)
                p->left=n->left;
            else
                p->left=n->right;
        }
        else
        {
          if(n->left!=NULL)
                p->right=n->left;
            else
                 p->right=n->right;
        }
    }
    free(n);
}
BST* cloneTree(BST *t1)
{


    BST *v;
    if(t1==NULL)
        return NULL;
    v=create_bst(t1->key);
    v->left=cloneTree(t1->left);
    v->right=cloneTree(t1->right);
    return v;
}
int areEqualTree(BST *t1,BST *t2)
{
    return (t1==NULL && t2==NULL) || (t1!=NULL && t2!=NULL && t1->key==t2->key && areEqualTree(t1->left,t2->left) && areEqualTree(t1->right,t2->right));
}
/*BST *predecessor(BST *prev,BST *t,int k)
{
     static BST* f;
    if((t->right==NULL && t->left==NULL))
        return NULL;
   predecessor(t,t->left,k);
   if(t->key==k)
   {
       f=prev;
        return prev;
    }
   predecessor(t,t->right,k);
   return f;
}*/
void makeInorderArray(BST *t,int *a)
{
    if(t==NULL)
        return;
    makeInorderArray(t->left,a+1);
    a[0]=t->key;
    makeInorderArray(t->right,a+1);
}
int showBST(BST *root, int x, int y, int *w, int *h)
{
    int lw, rw ;           /* Widths  of left and right subtrees */
    int lh, rh ;           /* Heights of left and right subtrees */
    int i, leftX, rightX ;

    if(root == NULL)
	   *w = *h = 0 ;
    else
    {
	   /* Print left subtree */

	   leftX = showBST(root->left, x, y+1, w, h) ;
	   lw = *w ;
	   lh = *h ;

	   /* Print right subtree */
	   rightX = showBST(root->right, x + lw + GAPS, y+1, w, h) ;
	   rw = *w ;
	   rh = *h ;

	   /* Print the root node */
	   x += lw ;
	   gotoxy(x, y) ;
	   printf("%-*d", GAPS, root->key) ;


	   /* Print graphical line for the left subtree */
	   if(lw > 0)
	   {
		 gotoxy(leftX, y) ; putchar('Ú') ;
		 for(i = leftX+1 ; i < x ; i ++)
		 {
		    gotoxy(i, y) ;
		    putchar('Ä') ;
		 }
	   }

	   /* Print graphical line for the right subtree */
	   if(rw > 0)
	   {
		 for(i = x + GAPS ; i <= rightX ; i ++)
		 {
		    gotoxy(i, y) ;
		    putchar('Ä') ;
		 }
		 gotoxy(rightX, y) ; putchar('¿') ;
	   }


	   *w = lw + rw + GAPS;
	   *h = (lh > rh ? lh : rh) + 1 ;
    }

    return x ;
}
int main()
{
	int ch,d,v;
	BST *t=NULL,*x,*tcopy,*t1=NULL;int w,h,*c,i;
	int a[]={53,28,77,62,60,70,16,42,20,30,50,48};
	int b[]={53,28,77,7,53,12,16,42,20,30,50,48};
 	int n=sizeof(a)/sizeof(a[0]);
	/*for(i=0;i<n;i++)
        insert_key_iterative(&t,a[i]);*/
    n=sizeof(b)/sizeof(b[0]);
    for(i=0;i<n;i++)
        insert_key_iterative(&t1,b[i]);
	while(1)
	{
		printf("\n1.Insert Key\n2.Search Key\n3.Print InOrder\n4.Print PreOrder\n5.Print PostOrder\n6.Find Minimum Node\n7.Find Maximum Node\n8.Count number of Nodes\n9.Find Height\n10.Delete Entire Tree\n11.Delete Key\n12.Convert to Mirror Tree\n13.Make Clone Tree\n14.Check Equal Tree\n15.Show Binary Search Tree\n16.Find InOrder Predecessor\n17.Exit\n\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	printf("\nEnter key:");
					 scanf("%d",&d);
					insert_key_iterative(&t,d);
					break;
			case 2:	printf("\nEnter key:");
				      scanf("%d",&d);
					x=search_key_recursive(t,d);
					if(x==NULL)
						printf("\nKey not found\n");
					else
						printf("\nKey found\n");
					break;
			case 3:	inorder(t);
					break;
			case 4:	preorder(t);
					break;
			case 5:	postorder(t);
					break;
			case 6:	printf("\nThe minimum node is with key %d\n",getMinNode(t)->key);
					break;
			case 7:	printf("\nThe maximum node is with key %d\n",getMaxNode(t)->key);
					break;
			case 8:	printf("\nThe number of nodes in the tree is %d\n",countNodes(t));
					break;
			case 9:printf("\nThe Height of the tree is %d.\n",getHeight(t));
                    break;
            case 10: deleteBST(t);
                    t=NULL;
                    break;
            case 11: printf("\nEnter key to delete:");
				      scanf("%d",&d);
				      delKey(&t,d);
                        break;
             case 12:  MirrorTree(t);
                            break;
            /*  case 13: tcopy=cloneTree(t);
                            showBST(tcopy,0,wherey()+1,&w,&h);
                            gotoxy(0,wherey()+h+1);
                            break;*/
                case 14: if(areEqualTree(t,t1))
                                printf("\nThe two trees are equal.\n");
                          else
                                printf("\nThe two trees are not equal.\n");
                          break;
                 case 15: showBST(t,0,wherey()+1,&w,&h);
                            gotoxy(0,wherey()+h+1);
                            break;
                 case 16: printf("\nEnter key:");
                        scanf("%d",&d);
                        x=search_key_recursive(t,d);
                        if(x==NULL)
                        {
                            printf("\nKey not found\n");
                            break;
                        }
                        /*if(predecessor(NULL,t,d)!=NULL)
                            printf("\nThe predecessor of node with key %d is %d.\n",d,predecessor(NULL,t,d)->key);
                         else
                                printf("\nThe node with key %d has no predecessor.\n",d);*/
                         v=countNodes(t);
                        c=(int*)malloc(v*sizeof(int));
                        makeInorderArray(t,c);
                        for(i=0;i<v;i++)
                                printf("%d\t",c[i]);
                        break;
                case 17:exit(1);


		}
	}
}
//C:\Program Files (x86)\NVIDIA Corporation\PhysX\Common;C:\Program Files (x86)\Lenovo\FusionEngine;C:\Program Files (x86)\Intel\iCLS Client\;C:\Program Files\Intel\iCLS Client\;%SystemRoot%\system32;%SystemRoot%;%SystemRoot%\System32\Wbem;%SYSTEMROOT%\System32\WindowsPowerShell\v1.0\;C:\Program Files (x86)\ATI Technologies\ATI.ACE\Core-Static;C:\Program Files\Intel\Intel(R) Management Engine Components\DAL;C:\Program Files (x86)\Intel\Intel(R) Management Engine Components\DAL;C:\Program Files\Intel\Intel(R) Management Engine Components\IPT;C:\Program Files (x86)\Intel\Intel(R) Management Engine Components\IPT;C:\Program Files\Lenovo\Bluetooth Software\;C:\Program Files\Lenovo\Bluetooth Software\syswow64;C:\Program Files (x86)\Windows Kits\8.1\Windows Performance Toolkit\;C:\Program Files\Microsoft SQL Server\110\Tools\Binn\;C:\Program Files (x86)\Microsoft SDKs\TypeScript\1.0\;C:\Program Files\Microsoft SQL Server\120\Tools\Binn\;C:\Program Files (x86)\Common Files\lenovo\easyplussdk\bin;C:\Program Files\VDownloader;C:\Program Files (x86)\Skype\Phone\
