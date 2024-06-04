#include<stdio.h>
int main()
{
    char ch[]="Lazmi Rahman";
    printf("%s\n",ch);
char a[]=strrev(ch);
    printf("reversed string: %s\n",ch);

    int d=strcmp(ch,strrev(ch));
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
