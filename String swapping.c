#include<stdio.h>
int main()
{
    char s1[15]="Lazmi";
    char s2[15]="Emon";
    char temp[15];
    printf("Before swapping:\n");
    printf("string 1= %s\n",s1);
    printf("string 2=%s\n",s2);

    strcpy(temp,s1);
    strcpy(s1,s2);
    strcpy(s2,temp);

    printf("After swapping:\n");
    printf("string 1= %s\n",s1);
    printf("string 2=%s\n",s2);
    return 0;
}
