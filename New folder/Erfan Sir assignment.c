#include <stdio.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
}

int main()
{
    FILE *file;
    int arr[1000], n = 0;

    file = fopen("1000.txt", "r");

    while (fscanf(file, "%d", &arr[n]) == 1)
    {
        n++;
    }

    fclose(file);

    bubbleSort(arr, n);

    printf("Sorted array: ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
