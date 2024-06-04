#include<stdio.h>
#include<math.h>
int main()
{
    int A[6][6];
    int i,j,r,c;
    for(i=1;i<=5;i++)
    {
        for(j=1;j<=5;j++)
        {
           scanf("%d ",&A[i][j]);
            if(A[i][j]==1)
            {
            r=abs(3-i);
            c=abs(3-j);
            }
        }
    }
    printf("%d",r+c);
    return 0;

}
