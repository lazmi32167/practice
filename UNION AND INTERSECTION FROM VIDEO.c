#include<bits/stdc++.h>
using namespace std;

int printUnion(int a1[],int a2[],int m,int n)
{
    int i=0,j=0;
    while(i<m && j<n)
    {
        if(a1[i]<a2[j])
        {
            printf("%d",a1[i++]);
        }
        else if(a2[j]<a1[i])
        {
            printf("%d",a2[j++]);
        }
        else
        {
            printf("%d",a2[j++]);
            i++;
        }
    }
    while(i<m)
    {
        printf("%d",a1[i++]);
    }
    while(j<n)
    {
        printf("%d",a2[j++]);
    }
}
int main()
{
    freeopen("unionlab.txt","r",stdin);
    freeopen("output.txt","w",stdout);
    int a1[10],a2[10];
    for(int i=0;i<10;i++)
    {
        scanf("%d",a1[i]);
    }

    for(int i=0;i<10;i++)
    {
        scanf("%d",a2[i]);
    }

    int m=sizeof(a1)/sizeof(a1[0]);
    int n=sizeof(a2)/sizeof(a2[0]);
    printUnion(a1,a2,m,n);
    //getchar();
    return 0;
}
