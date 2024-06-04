#include <stdio.h>
#include <math.h>

void printSubset(int arr[], int n, int mask)
{
    printf("{ ");
    for (int i = 0; i < n; i++) {
        if ((mask & (1 << i)) != 0) {
            printf("%d ", arr[i]);
        }
    }
    printf("}\n");
}

void generatePowerSet(int arr[], int n) {
    int totalSubsets = pow(2, n);

    printf("Power Set:\n");
    for (int mask = 0; mask < totalSubsets; mask++) {
        printSubset(arr, n, mask);
    }
}

int main()
{
    FILE *file;
    int i, j;

    file = fopen("setdata.txt","r");
    if(file == NULL);
    printf("Error opening file");
    int arr[20];

    fscanf(file, "%d", &i);
    for(j = 0; j<i; j++)
    {
        fscanf(file, "%d", &arr[j]);
    }
    fclose(file);

    generatePowerSet(arr, i);

    return 0;
}
