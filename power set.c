#include <stdio.h>
#include <math.h>

void printSubset(char arr[], int n, int mask) {
    printf("{ ");
    for (int i = 0; i < n; i++) {
        if ((mask & (1 << i)) != 0) {
            printf("%c ", arr[i]);
        }
    }
    printf("}\n");
}

void generatePowerSet(char arr[], int n) {
    int totalSubsets = pow(2, n);

    printf("Power Set:\n");
    for (int mask = 0; mask < totalSubsets; mask++) {
        printSubset(arr, n, mask);
    }
}

int main() {
    char arr[] = {'A','B','C'};
    int n = sizeof(arr) / sizeof(arr[0]);

    generatePowerSet(arr, n);

    return 0;
}
