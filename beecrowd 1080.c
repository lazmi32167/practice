#include <stdio.h>
int main() {

    int a[100];
    int i,max,pos;
    for(i=0;i<100;i++)
    {
       scanf("%d",&a[i]);
        max=a[0];
    }
        for(i=1;i<100;i++)
        {
            if(a[i]>max)
   {
       max=a[i];
       pos=i+1;
       printf("%d\n",max);
       printf("%d\n",pos);
   }
        }

    return 0;
}

