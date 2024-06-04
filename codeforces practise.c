#include<stdio.h>
int main()
{
    int n,i;
    char s1[100];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        gets(s1);
    }
    int len=strlen(s1[i]);
         printf("%d",len);
         if(len<=10)
         {
             printf("%s",s1[i]);
         }
    int len=strlen(s1);
    printf("%d",len);

}
