#include <stdio.h>

#define MAX_SIZE 100

int main() {
    FILE *file;
    file = fopen("unionlab.txt", "r");

    if (file == NULL) {
        printf("file doesn't exist\n");
        return 1;
    }

    int A[MAX_SIZE], B[MAX_SIZE];
    int sizeA = 0, sizeB = 0;
    int count;

    fscanf(file, "%d", &count);
    while (fscanf(file, "%d", &count) == 1) {
        A[sizeA++] = count;
    }

    fscanf(file, "%d", &count);
    while (fscanf(file, "%d", &count) == 1) {
        B[sizeB++] = count;
    }

    int ar[MAX_SIZE * 2];
    int size = 0;

    for (int i = 0; i < sizeA; i++) {
        ar[size++] = A[i];
    }
    for (int i = 0; i < sizeB; i++) {
        ar[size++] = B[i];
    }

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size;) {
            if (ar[i] == ar[j]) {
                for (int k = j; k < size - 1; k++) {
                    ar[k] = ar[k + 1];
                }
                size--;
            } else {
                j++;
            }
        }
    }

    printf("Union of the sets:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", ar[i]);
    }
    printf("\n");

    return 0;
}
