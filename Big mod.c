#include<stdio.h>

int bigMod(int base, int power, int mod)
{
    int a,b;
    if(power==0)
        return 1;
    else if(power%2==1)
    {
        a = base % mod;
        b =bigMod(base, power-1, mod);
        return (a*b)%mod;
    }
    else if(power%2==0)
    {
        a = bigMod(base, power/2, mod);
        return (a*a)%mod;
    }
}
int main(){
    int base, power, mod;
    printf(" Input Base, Power , Mod \n");
    scanf("%d %d %d",&base,&power,&mod);
    int result = bigMod(base, power, mod);
    printf("(%d^%d) %% %d = %d\n", base, power, mod, result);
}
