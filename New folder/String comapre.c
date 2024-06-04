#include<stdio.h>
int main()
{
    char s1[]="Lazmi Rahman";
    char s2[]="Emon Rayhan";
    int result=strcmp(s1,s2);
    if(result==0)
    {
        printf("strings are equal");
    }
    else
    {
         printf("strings are not equal");
    }
    return 0;
}
