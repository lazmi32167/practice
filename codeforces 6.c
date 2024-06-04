#include<stdio.h>
int main()
{
    int n,i,X=0;
    char op;
    scanf("%d",&n);
   for(i=0;i<n;i++)
   {
       scanf("%c",&op);
       switch(op)
       {
       case 'X++':
        {
            X==0;
            X++;
            break;
        }
       case 'X--' :
        {
           X==0;
           X--;
           break;
        }
       case '++X' :
        {
           X==1;
           X++;
           break;
       }
       case '--X' :
        {
           X==-1;
           X--;
           break;
       }
        }
   }
   printf("%d",X);
   return 0;
}
