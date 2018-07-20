#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int i,i1,a0,q_i,T; 
    scanf("%d",&T);
    for( a0 = 0; a0 < T; a0++){
        int n,swap=0,j=0,k; 
        scanf("%d",&n);
        int *q = (int*)malloc(sizeof(int) * n);
        int *r= (int*)malloc(sizeof(int) * n);
        for( q_i = 0; q_i < n; q_i++){
           scanf("%d",&q[q_i]);
        }
        int flag=0;
      for(i=0;i<n;i++)
          {
                for(k=0;k<j;k++)
                    if(r[k]==q[i])
                    {
                         flag=1;//set
                        break;
                      }
                    if(flag==1)
                        {
                        flag=0;
                        continue;
                    }
          
              i1=i+1;
              i1=abs(q[i]-i1);
              if(i1!=0)
                  {
                     if(i1>2)
                        {
                            printf("Too chaotic\n");
                            exit(7);
                        }

                        ++swap;
                        r[j++]=i+1;

                  }   
      }
        printf("%d\n",swap);
        
        
      /* for(k=0;k<j;k++)
           printf("%d\n",r[k]);*/
       // printf("%d=j",j);
        
    }
    return 0;
}

