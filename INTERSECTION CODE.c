#include<stdio.h>
int printintersection(int a1[],int a2[],int m,int n)
{
 int i=0,j=0;
 while(i<m && j<n)
 {
     if(a1[i]<a2[j])
     {
         i++;
     }
     else if(a2[j]<a1[i])
     {
         j++;
     }
     else
       {
        printf("%d",a2[j++]);
        i++;
     }
 }
 }
int main()
{
    int a1[]={1,3,5,7};
    int a2[]={2,3,4,7};
    int m=sizeof(a1)/sizeof(a1[0]);
    int n=sizeof(a2)/sizeof(a2[0]);
    printintersection(a1,a2,m,n);
    //getchar();
    return 0;
}
