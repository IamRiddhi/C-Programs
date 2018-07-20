/*Sort first half of the array in ascending order , second half in descending order and keep the diff
of sum of two parts in the middle*/
#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
/* if order is true sort in ascending order else in descending order*/ 
bool comp(int a,int b,bool order)
{
    if(order)
        return a>b;
    else 
        return a<b;
}
void sort(int *a,int l,int r,bool order)
{
    for(int i=r;i>l;i--)
        for(int j=l;j<i;j++)
            if(comp(a[j],a[j+1],order))
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
}
int main(void)
{
	int n;
	scanf("%d",&n);
	int *ar = (int*)(malloc(n*sizeof(int)));
	int *prefixSum = (int*)(malloc(n*sizeof(int)));
	for(int i=0;i<n;i++)
	    scanf("%d",&ar[i]);
	    
	prefixSum[0] = ar[0];
	for(int i=1;i<n;i++)
	    prefixSum[i] = ar[i] + prefixSum[i-1];
	int mid = n/2;
	int diff = abs(prefixSum[mid-1] - (prefixSum[n-1] - prefixSum[mid]) );    
	sort(ar,0,mid-1,true);
	sort(ar,mid+1,n-1,false);
	ar[mid] = diff;
	for(int i=0;i<n;i++)
	    printf("%d ",ar[i]);
}

