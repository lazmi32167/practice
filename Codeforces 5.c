#include<stdio.h>
int main()
{
    int n,k,i,s[50],count=0;
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++)
    {
        scanf("%d",&s[i]);
    }
    for(i=0;i<n;i++)
    {
        if(s[i]>=s[k-1] && s[i]>0)
        {
            count++;
        }
    }
    printf("%d",count);
    return 0;
}
