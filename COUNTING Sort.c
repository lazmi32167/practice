#include <stdio.h>
#include <stdlib.h>

void countingSort(int array[], int size) {
  int max = array[0];
  for (int i = 1; i < size; i++) {
    if (array[i] > max)
      max = array[i];
  }

  int* count = (int*)malloc((max + 1) * sizeof(int));
  for (int i = 0; i <= max; ++i) {
    count[i] = 0;
  }

  for (int i = 0; i < size; i++) {
    count[array[i]]++;
  }

  for (int i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }

  int* output = (int*)malloc(size * sizeof(int));
  for (int i = size - 1; i >= 0; i--) {
    output[count[array[i]] - 1] = array[i];
    count[array[i]]--;
  }

  for (int i = 0; i < size; i++) {
    array[i] = output[i];
  }

  free(count);
  free(output);
}

void printArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

int main() {
  int n;
  freopen("input.txt","r",stdin);

  printf("Enter the number of elements: ");
  scanf("%d", &n);
  int* array = (int*)malloc(n * sizeof(int));
  printf("Enter the elements: ");
  for(int i=0; i<n; i++) {
    scanf("%d", &array[i]);
  }
  countingSort(array, n);
  printf("Sorted array: ");
  printArray(array, n);
  free(array);
}
