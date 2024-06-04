#include<stdio.h>
#include <stdlib.h>
void InsertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
     printf("Insertion Sorted array: \n");
     for (int i=0; i <n; i++)
        printf("%d ", arr[i]);
      printf("\n");
}

int main()
{

    int A[]={6,8,2,3,6,9};
    int n=6;

    InsertionSort(A,n);
    return 0;
}
