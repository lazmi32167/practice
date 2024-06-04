#include<stdio.h>
int main()
{
    char er[]="LAzmi Rahman";
    int i=0,count=0;
    while(er[i]!='\0')
    {
        count++;
        i++;
    }
    printf("Length = %d\n",count);
    return 0;
}
