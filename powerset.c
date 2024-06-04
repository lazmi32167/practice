#include<stdio.h>
#include<math.h>
void printSubset(char ar[],int n,int mask)
{
    printf("{");
    for(int i=0;i<n;i++)
    {
       if( ((1<<i)&mask) !=0)
       {
        printf("%c",ar[i]);
       }
    }
    printf("}\n");
}
void generatePowerSet(char ar[],int n)
{
    int totalsubset=pow(2, n);
    printf("Power Set :\n");
    for(int mask=0;mask<totalsubset;mask++)
    {
        printSubset(ar,n,mask);
    }
    }
int main()
{
    char ar[]={'L','A','Z','m'};
    int n=sizeof(ar) / sizeof(ar[0]);
    generatePowerSet(ar,n);
    return 0;