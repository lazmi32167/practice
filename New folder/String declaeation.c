#include<stdio.h>
int main()
{
    char s1[30];
    printf("Enter your full name: ");
    //gets is used insted of scanf because gets can get the whole name including space
    gets(s1);
    printf("Full name: %s",s1);
    return 0;
}
