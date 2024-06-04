#include<stdio.h>
int main()
{
    char ch[]="Lazmi Rahman";
    char a[50];
    strcpy(a,ch);
    strrev(ch);
    printf("reversed string: %s\n",ch);

    int d=strcmp(ch,a);
    if(d==0)
    {
        printf("Strings are palindrome");

    }
    else
        {
            printf("Strings are not palindrome");

        }
        return 0;
}
