
#include<stdio.h>
#include<stdlib.h>
#define max 256
typedef struct
{
	int freq;
	int right;
	int left;
}Node;
Node nodes[2*max]={0};
typedef struct
{
	int arr[max];// stores node indices.
	int len;
}mq;
void init(mq *q)
{
	q->len=0;
}
int isEmpty(mq *q)
{
	return (q->len==0);
}
void insert(mq *q, int ndIndex)
{
	int p,c,e,l=q->len;
	e=nodes[ndIndex].freq;
	c=l;
	p=(c-1)/2;
	while(c>0 && e<nodes[q->arr[p]].freq)
	{
        q->arr[c]=q->arr[p];
        c=p;
        p=(c-1)/2;

	}
	q->arr[c]=ndIndex;
	q->len++;

}
int remove(mq *q)
{
	int minIndex=q->arr[0];
	int c=1,p=0,l=q->len; // c=child
	int e=nodes[q->arr[l-1]].freq;
	if(c+1<l && nodes[q->arr[c+1]].freq < nodes[q->arr[c]].freq)
		c=2;
	while(c<l && nodes[q->arr[c]].freq<e)
	{
		q->arr[p]=q->arr[c];
		p=c;
		c=2*p+1;
		if(c+1<l && nodes[q->arr[c+1]].freq < nodes[q->arr[c]].freq)
			c++;
	}
	q->arr[p]=q->arr[l-1];
	q->len--;
	return minIndex;

}
void FreqOfChar(char *fname)
{
	FILE *fp;
	int e;
	fp=fopen(fname,"rb");
	while(1)
	{
		e=fgetc(fp);
		if(e==EOF)
            break;
		nodes[e].freq++;
	}
	fclose(fp);
}
int main()
{
	int i,b;
	mq q;
	init(&q);
	char fname[]="c:\\users\\lenovo\\desktop\\alice in wonderland.txt";
	FreqOfChar(fname);
	for(i=0;i<max;i++)
        if(nodes[i].freq!=0)
            printf("%d=%d\n",i,nodes[i].freq);
	printf("\nAfter Sorting\n");
	for(i=0;i<max;i++)
        if(nodes[i].freq!=0)
            insert(&q,i);
    while(!isEmpty(&q))
    {
        b=remove(&q);
        printf("%d=%d\n",b,nodes[b].freq);
    }
}

