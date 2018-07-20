/* 
 * File:   GreTreeListRecursion.c
 * Author: Prosenjit Banerjee
 *
 * Created on 15 October, 2016, 3:22 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Creates and recursively converts and Binary Search Tree to a doubly circular linked list
 */

typedef struct Node
{
    int data ;
    struct Node *left ;
    struct Node *rite ;
} Node ;

Node *createNode(int data)
{
    Node *node = (Node *) malloc(sizeof(Node)) ;
    node->data = data ;
    node->left = NULL ;
    node->rite = NULL ;

    return node ;
}

void insertKey(Node **root, int key)
{
    Node *t = *root ;
    Node *p ;
    char dir ;

    if(t == NULL)
        *root = createNode(key) ;
    else
    {
        while(t != NULL)
        {
            p = t ;
            if(key <= t->data)
            {
                dir = 'L' ;
                t = t->left ;
            }
            else
            {
                dir = 'R' ;
                t = t->rite ;
            }
        }
        if(dir == 'L')
            p->left = createNode(key) ;
        else
            p->rite = createNode(key) ;
    }
}

void inorderRecursive(Node *t)
{
    if(t == NULL)
        return ;

    inorderRecursive(t->left) ;
    printf("%4d", t->data) ;
    inorderRecursive(t->rite) ;
}

void printForward(Node *root)
{
    Node *t = root ;
    if(root == NULL)
       return ;

    do
    {
        printf("%4d", t->data) ;
        t = t->rite ;
    } while(t != root) ;

    puts("") ;
}

void printBackward(Node *root)
{
    Node *t = root ;
    if(root == NULL)
       return ;

    do
    {
        t = t->left ;
        printf("%4d", t->data);
    } while(t != root) ;

    puts("") ;
}


Node *treeListRecursion(Node *t)
{
   Node *ltStart, *ltEnd, *rtStart, *rtEnd ;

   if(t == NULL)
      return NULL ;

    if(t->left == NULL)
        ltStart = ltEnd = t ;
    else
    {
        ltStart = treeListRecursion(t->left) ;
        ltEnd = ltStart->left ;

        t->left = ltEnd ;
        ltEnd->rite = t ;
    }

    if(t->rite == NULL)
        rtStart = rtEnd = t ;
    else
    {
        rtStart = treeListRecursion(t->rite) ;
        rtEnd = rtStart->left ;

        t->rite = rtStart ;
        rtStart->left = t ;
    }


    ltStart->left = rtEnd ;
    rtEnd->rite = ltStart ;

    return ltStart ;
}

int main (void)
{

    int ar[] = {35, 15, 82, 10, 16, 38, 48, 53, 78, 26} ;
    int n = sizeof(ar) / sizeof(ar[0]) ;
    int i ;
    Node *root = NULL ;

    for(i = 0 ; i < n ; i ++)
        insertKey(&root, ar[i]) ;

    inorderRecursive(root) ;
    puts("") ;

    root = treeListRecursion(root) ;
    printForward(root) ;
    printBackward(root) ;

    return 0 ;
}
