#include<stdio.h>
int printUnion(int A[10],int B[10],int m,int n)
{
    int i=0,j=0;
    while(i<m && j<n)
    {
        if(A[i] < B[j])
        {
            printf("%d",A[i++]);
        }
        else if(B[j]<A[i])
        {
            printf("%d",B[j++]);
        }
        else
        {
            printf("%d",B[j++]);
            i++;
        }
    }
    while(i<m)
    {
        printf("%d",A[i++]);
    }
    while(j<n)
    {
        printf("%d",B[j++]);
    }

}
int main()
{
    FILE *file;
    file = fopen("unionlab.txt", "r");

    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    int A[10],B[10];
    int m,n,i,j,count;
    fscanf(file,"%d",&count);
    while (fscanf(file, "%d", &count) == 1) {
        A[i++] = count;
    }
    while (fscanf(file, "%d", &count) == 1) {
        B[j++] = count;
    }
    fclose(file);

    m=sizeof(A) / sizeof(A[0]);
    n=sizeof(B) / sizeof(B[0]);
    printUnion(A,B,m,n);
    return 0;
}
