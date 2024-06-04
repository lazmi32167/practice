#include<stdio.h>
int main()
{
    long long int n,m,a,l,w;
    scanf("%lld%lld%lld",&n,&m,&a);
    l=n/a;
    if(n%a!=0)
    {
        l++;
    }
    w=m/a;
    if(m%a!=0)
    {
        w++;
    }
    printf("%lld",l*w);
    return 0;
}
//israt.tamanna_000
