
#include<stdio.h>
#include <stdlib.h>
#include <time.h>

// Bubble Sort
void bubbleSort(int arr[], int n) {
 int i, j, temp;
 for (i = 0; i < n-1; i++) {
     for (j = 0; j < n-i-1; j++) {
         if (arr[j] > arr[j+1]) {
             temp = arr[j];
             arr[j] = arr[j+1];
             arr[j+1] = temp;
         }
     }
 }
}

// Insertion Sort
void insertionSort(int arr[], int n) {
 int i, key, j;
 for (i = 1; i < n; i++) {
     key = arr[i];
     j = i - 1;
     while (j >= 0 && arr[j] > key) {
         arr[j + 1] = arr[j];
         j = j - 1;
     }
     arr[j + 1] = key;
 }
}

// Heap Sort
void heapify(int arr[], int n, int i) {
 int largest = i;
 int left = 2*i + 1;
 int right = 2*i + 2;
 if (left < n && arr[left] > arr[largest])
     largest = left;
 if (right < n && arr[right] > arr[largest])
     largest = right;
 if (largest != i) {
     int swap = arr[i];
     arr[i] = arr[largest];
     arr[largest] = swap;
     heapify(arr, n, largest);
 }
}

void heapSort(int arr[], int n) {
 for (int i = n / 2 - 1; i >= 0; i--)
     heapify(arr, n, i);
 for (int i=n-1; i>=0; i--) {
     int temp = arr[0];
     arr[0] = arr[i];
     arr[i] = temp;
     heapify(arr, i, 0);
 }
}

// Counting Sort
void countSort(int arr[], int n) {
    int i, max = arr[0], min = arr[0];

    // Find the maximum and minimum elements in the array
    for (i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }

    int range = max - min + 1;
    int count[range], output[n];
    for (i = 0; i < range; ++i)
        count[i] = 0;
    for (i = 0; i < n; ++i)
        count[arr[i]-min]++;
    for (i = 1; i < range; ++i)
        count[i] += count[i-1];
    for (i = n-1; i >= 0; i--) {
        output[count[arr[i]-min]-1] = arr[i];
        count[arr[i]-min]--;
    }
    for (i = 0; i < n; ++i)
        arr[i] = output[i];
}


int main() {

    freopen("1000.txt","r",stdin);
    clock_t start,end;
    double cpu_time_used;
    int n;
    scanf("%d",&n);
    int arr[n];
int i = 0;
while (i < n) {
    scanf("%d",&arr[i]);
    i++;
}


 /*printf("Original array: \n");
 for (int i=0; i <n; i++)
     printf("%d ", arr[i]);
 printf("\n");*/
 start=clock();
 bubbleSort(arr, n);
 end=clock();
 cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;
 printf("Bubble Sorted array: \n");
 for (int i=0; i <n; i++)
     printf("%d ", arr[i]);
 printf("Time taken: %f\n",cpu_time_used);
 printf("\n");

 insertionSort(arr, n);
 printf("Insertion Sorted array: \n");
 for (int i=0; i <n; i++)
     printf("%d ", arr[i]);
 printf("\n");

 heapSort(arr, n);
 printf("Heap Sorted array: \n");
 for (int i=0; i <n; i++)
     printf("%d ", arr[i]);
 printf("\n");

 countSort(arr, n);
 printf("Counting Sorted array: \n");
 for (int i=0; i <n; i++)
     printf("%d ", arr[i]);
 printf("\n");

 return 0;
}
