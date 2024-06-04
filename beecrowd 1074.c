#include<stdio.h>
int main() {
    int N,i,X;
    scanf("%d",&N);
 for(i=1;i<=N;i++)
 {
     scanf("%d",&X);
      if(X==0)
     {
         printf("NULL\n");
     }
   else if(X<0)
    {
        if(X%2==0)
        {
            printf("EVEN NEGATIVE\n");
        }
        else
        {
           printf("ODD NEGATIVE\n");
        }
    }
    else
    {
        if(X%2==0)
        {
            printf("EVEN POSITIVE\n");
        }
        else
        {
           printf("ODD POSITIVE\n");
        }
    }
 }

 return 0;
}

