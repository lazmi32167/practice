#include<stdio.h>
int main()
{
    int A[3][3],i,j,sum=0;
    printf("Enter the elements of matrix: \n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("A[%d][%d]= ",i,j);
            scanf("%d",&A[i][j]);
        }
    }
    printf("Entered matrix\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",A[i][j]);
    }
    printf("\n");
}
printf("Diagonal elements are: ");
 for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(i==j)
            {
                printf("%d ",A[i][j]);
              sum=sum+A[i][j];
            }
    }
}
printf("\nSum of diagonal elements are %d\n",sum);
return 0;
}
