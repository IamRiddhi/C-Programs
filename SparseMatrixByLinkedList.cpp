/* 
 * File:   SparseMatrixByLinkedList.c
 * Author: Prosenjit Banerjee
 *
 * Created on 16 October, 2016, 2:48 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * A linked List implemented Sparse Matrix with float elements
 */

#define BLANK 0.0
#define INFINITY 32767

typedef struct Sparse
{
    int row ;
    int col  ;
    float val ;
    struct Sparse *riteElem ;
    struct Sparse *downElem ;
} Sparse ;

Sparse *createNewNode(int row, int col, float val)
{
    Sparse *sp = (Sparse *) malloc(sizeof(Sparse)) ;
    sp->row = row ;
    sp->col = col ;
    sp->val = val ;
    sp->riteElem = sp->downElem = sp ;
    
    return sp ;
}

Sparse *createNewSparse(int maxRows, int maxCols)
{
    int i ;
    Sparse *t, *node ;
    
    Sparse *sp = createNewNode(maxRows, maxCols, 0) ;
    
    /* Create the column heads */
    t = sp ;
    for(i = 0 ; i < maxCols ; i ++)
    {
        node = createNewNode(INFINITY, i, 0) ;
        
        node->riteElem = t->riteElem ;
        t->riteElem = node ;
        t = node ;
    }
    

    /* Create the row heads */
    t = sp ;
    for(i = 0 ; i < maxRows ; i ++)
    {
        node = createNewNode(i, INFINITY, 0) ;
        
        node->downElem = t->downElem ;
        t->downElem =  node ;
        t = node ;
    }
    
    return sp  ;
}

Sparse* createFromArray(float ar[][30], int rows, int cols, int maxRows, int maxCols)
{
    Sparse *sp, *r, *c, *node, *temp ;
    int i, j ;
    
    sp = createNewSparse(maxRows, maxCols) ;
    
    r = sp ;
    for(i = 0 ; i < rows ; i ++)
    {
        node = r = r->downElem ;

        c = sp ;
        for (j = 0 ; j < cols ; j++)
        {
            c = c->riteElem ;
            
            if(ar[i][j] != BLANK)
            {
                temp = createNewNode(i, j, ar[i][j])  ;
                temp->riteElem = node->riteElem ;
                node->riteElem = temp ;
                node = temp ;
                
                if(c->downElem != c)
                    node->downElem = c->downElem->downElem ;
                c->downElem->downElem = node ;
                c->downElem = node ;
            }
        }
    }

    // Adjust the column heads
    c = sp ;
    for (j = 0 ; j < cols ; j++)
    {
        c = c->riteElem ;
        r = c->downElem ;
        c->downElem = r->downElem ;
        r->downElem = c ;
        
    }
    
    return sp ;
}

Sparse *multSparse(Sparse *spA, Sparse *spB)
{
    Sparse *spC = NULL ;
    
    Sparse *r, *c, *a, *b, *aNode, *bNode, *cNode, *temp ;
    int i, j ;
    float sum ;
    
    if(spA->col != spB->row)
    {
        puts("Number of rows of first matrix not same as that of column of the second") ;
        return NULL ;
    }

    spC = createNewSparse(spA->row, spB->col) ;
    
    r = spC ;
    
    aNode = spA ;
    for(i = 0 ; i < spC->row ; i ++)
    {
        aNode = aNode->downElem ;
        bNode = spB ;
        cNode = r = r->downElem ;

        c = spC ;
        for (j = 0 ; j < spC->col ; j++)
        {
            bNode = bNode->riteElem ;

            a = aNode->riteElem ;
            b = bNode->downElem ;
            sum = 0 ;
            
            while(a != aNode && b != bNode)
                if(a->col < b->row)
                    a = a->riteElem ;
                else if(b->row < a->col)
                    b = b->downElem ;
                else
                {
                    sum += a->val * b->val ;
                    a = a->riteElem ;
                    b = b->downElem ;
                }

            c = c->riteElem ;
            
            if(sum != BLANK)
            {
                temp = createNewNode(i, j, sum)  ;
                
                temp->riteElem = cNode->riteElem ;
                cNode->riteElem = temp ;
                cNode = temp ;
                
                if(c->downElem != c)
                    cNode->downElem = c->downElem->downElem ;
                c->downElem->downElem = cNode ;
                c->downElem = cNode ;
            }
        }
    }

    // Adjust the column heads
    c = spC ;
    for (j = 0 ; j < spC->col ; j++)
    {
        c = c->riteElem ;
        r = c->downElem ;
        c->downElem = r->downElem ;
        r->downElem = c ;
        
    }
        
    
    return spC ;
}

float getVal(Sparse *sp, int row, int col)
{
    Sparse *node ;
    
    if(row > sp->row || col > sp->col)
    {
        puts("Illegal matrix index error!") ;
        return -999 ;
    }

    node = sp->downElem ;
    while(node->row != row)
        node = node->downElem ;

    node = node->riteElem ;
    while(node->col < col)
        node = node->riteElem ;
    
    
    return (node->col == col ? node->val : 0.0) ;
}

float setVal(Sparse *sp, int row, int col, float val)
{
    Sparse *node, *temp ;
    
    if(row > sp->row || col > sp->col)
    {
        puts("Illegal matrix index error!") ;
        return -999 ;
    }

    node = sp->downElem ;
    while(node->row != row)
        node = node->downElem ;

    while(node->riteElem->col < col)
        node = node->riteElem ;
    
    
    if(node->riteElem->col == col) // Element found
    {
        if(val != 0)
            node->riteElem->val = val ; // Replace valud
        else             // val is 0, so delete the node
        {
            temp = node->riteElem ;
            node->riteElem = temp->riteElem ;
            
            /* Go the the column header */
            node = sp->riteElem ;
            while(node->col != col)
                node = node->riteElem ;
            
            /* Reach to the element */
            while(node->downElem != temp)
                node = node->downElem ;
            
            /* Detach it */
            node->downElem = temp->downElem ;
            
            free(temp) ;
        }
    }
    else                        // Element NOT found
    {
        if(val != 0)
        {   // Insert a new element
            temp = createNewNode(row, col, val) ;
            temp->riteElem = node->riteElem ;
            node->riteElem = temp ;
            
            /* Go the the column header */
            node = sp->riteElem ;
            while(node->col != col)
                node = node->riteElem ;
            
            /* Reach to the element */
            while(node->downElem->row < row)
                node = node->downElem ;
            
            /* Insert the new node */
            temp->downElem = node->downElem ;
            node->downElem = temp ;
        }
    }
        
}

Sparse* expensiveCreateFromArray(float ar[][30], int rows, int cols, int maxRows, int maxCols)
{
    Sparse *sp ;
    int i, j ;
    
    sp = createNewSparse(maxRows, maxCols) ;
    
    for(i = 0 ; i < rows ; i ++)
        for (j = 0 ; j < cols ; j++)
            setVal(sp, i, j, ar[i][j]) ;
            
    return sp ;
}

void printSparse(Sparse *sp)
{
    int i, j ;
    Sparse *r, *c ;
    
    r = sp->downElem ;
    for (i = 0 ; i < sp->row ; i++)
    {
        c = r->riteElem ;
        for (j = 0 ; j < sp->col ; j++)
            if(c->col == j)
            {
                printf("%7d", (int)c->val) ;
                c = c->riteElem ;
            }
            else
                printf("%7d", (int)BLANK) ;
                
        puts("") ;
        r = r->downElem ;
    }
}

void expensivePrintSparse(Sparse *sp)
{
    int i, j ;

    for (i = 0 ; i < sp->row ; i++)
    {
        for (j = 0 ; j < sp->col ; j++)
            printf("%7.2f", getVal(sp, i, j)) ;
        puts("") ;
    }
}

void destroySparse(Sparse *sp)
{
    Sparse *r, *c, *t ;
    
    if(sp == NULL)
        return ;
    
    r = sp->downElem ;
    while(r != sp)
    {
        c = r->riteElem ;
        while(c != r)
        {
            t = c ;
            c = c->riteElem ;
            free(t) ;
            
        }
        t = r ;
        r = r->downElem ;
        free(t) ;
    }
    
    c = sp->riteElem ;
    while(c != sp)
    {
        t = c ;
        c = c->riteElem ;
        free(t) ;
    }
    
    free(sp) ;
}

void transpose(Sparse *sp)
{
    /* This is nothing but exchanging row with col 
     * and downElem with riteElem of each node 
     */
    Sparse *r, *c, *tmpR, *tmpC ;
    Sparse *p ;
    int    k ;
    
    r = sp ;
    do
    {
        tmpR = r->downElem ;
        
        c = r ;
        do
        {
            tmpC = c->riteElem ;
            p = c->riteElem ; c->riteElem = c->downElem ; c->downElem = p ;
            k = c->row ; c->row = c->col ; c->col = k ;
            c = tmpC ;
        } while(c != r) ;
        
        r = tmpR ;
    } while(r != sp) ;
}

int main(int argc, char** argv)
{
    
    float ar[][30] = {
        { 0,  0, 24,  0, 0},
        { 0, 65,  0,  0, 89},
        { 0,  0,  0,  0,  0},
        {25,  0,  0,  0, 37},
        { 0,  0, 82,  0,  0},
        {38, 75,  0,  0, 12},
    } ;
    
    float br[][30] = {
        { 0,  0, 10},
        { 0, 20,  0},
        { 0,  0,  0},
        {30,  0,  0},
        { 0,  0, 40},
    } ;
    
//    float ar[][30] = {
//        { 1,  2, 3},
//        { 4,  5, 6},
//    } ;
//    
//    float br[][30] = {
//        { 0,  0},
//        { 9, 10},
//        {11, 12},
//    } ;
    
    Sparse *sp1, *sp2, *sp3 ;
    
    sp1 = createFromArray(ar, 6, 5, 6, 5) ;
    sp2 = createFromArray(br, 5, 3, 5, 3) ;

//    sp1 = createFromArray(ar, 2, 3, 2, 3) ;
//    sp2 = createFromArray(br, 3, 2,  3, 2) ;

//    sp1 = createFromArray(ar, 3, 5, 3, 5) ;
//    sp1 = expensiveCreateFromArray(ar, 6, 5, 6, 5) ;
    
    printSparse(sp1) ;
//    expensivePrintSparse(sp) ;
    
    puts("==============================================") ;
    printSparse(sp2) ;
    puts("==============================================") ;
    
    sp3 = multSparse(sp1, sp2) ;
    printSparse(sp3) ;

    


//    transpose(sp1) ;
//    printSparse(sp1) ;
    
    destroySparse(sp1) ;
    destroySparse(sp2) ;
    destroySparse(sp3) ;
    
    return (EXIT_SUCCESS) ;
}

