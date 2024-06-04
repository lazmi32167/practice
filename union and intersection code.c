#include<stdio.h>
#include <stdlib.h>
int compare(const void *x, const void *y){
    int *xx = (int*)x;
    int *yy = (int*)y;
    return *xx - *yy;
}
void section(int a[], int n, int b[], int p){
    int i, j;
    printf("{");
    for(i=0; i<n; i++){
        for(j=0; j<p; j++){
            if(a[i] == b[j]){
                printf(" %d ", a[i]);
            }
        }
    }
    printf("}\n\n");
}
void unionset(int a[], int n, int b[], int p){
    int u[n+p], i, j, k=n, c;
    for(i=0; i<n; i++){
        u[i] = a[i];
    }
    for(i=0; i<p; i++){
        c = 1;
        for(j=0; j<n; j++){
            if(a[j]==b[i])
                c = 0;
        }
        if(c==1){
            u[k] = b[i];
            k++;
        }
    }
    int x = (n+p)-2;
    qsort(u, x, sizeof(int), compare);
    printf("{");
    for(i=0; i<x-2; i++){
        printf(" %d,", u[i]);
    }
    printf("}\n\n");
}
int main ()
{
    FILE *file;
    file = fopen("intersection.txt", "r");
    if(file==NULL)
    {
        printf("File doesn't exist\n");
    }
    else
    {
        int A[8], B[8], i, x;
        for(i=0; i<7; i++){
            if (fscanf(file, "%d", &A[i]) != 1) {
                printf("Error reading from file.\n");
                fclose(file);
                return 1;
            }
            if (fscanf(file, "%d", &B[i]) != 1) {
                printf("Error reading from file.\n");
                fclose(file);
                return 1;
            }
        }
        printf("set A: { ");
        for (i = 0; i < 7; i++) {
        printf("%d, ", A[i]);
        }
        printf("}\n");

        printf("set B: { ");
        for (i = 0; i < 7; i++) {
            printf("%d, ", B[i]);
        }
        printf("}\n");
        do
        {
            printf("Menu :\n");
            printf("1. Set of intersection\n");
            printf("2. Set of Union\n");
            printf("3. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &x);
            switch(x)
            {
                case 1:
                    section(A, 7, B, 7);
                    break;
                case 2:
                    unionset(A, 7, B, 7);
                    break;
                case 3:
                    printf("Existing program\n");
            }
        } while(x != 3);

    }
    return 0;
}
