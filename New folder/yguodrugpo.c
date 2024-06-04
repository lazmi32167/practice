#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int arr[], int n, long long int *iterations) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            (*iterations)++;
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int *read_data_from_file(const char *file_path, int *size) {
    FILE *file = fopen(random_data, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int *data = NULL;
    int i = 0;

    while (fscanf(file, "%d", &data[i]) == 1) {
        i++;
    }

    *size = i;

    fclose(file);
    return data;
}

void write_data_to_file(const char *file_path, int *data, int size) {
    FILE *file = fopen(file_path, "w");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < size; i++) {
        fprintf(file, "%d\n", data[i]);
    }

    fclose(file);
}

int main() {
    const char *input_file_path = "random_data.txt";
    int size;
    int *data = read_data_from_file(input_file_path, &size);

    clock_t start_time = clock();
    long long int iterations = 0;
    bubble_sort(data, size, &iterations);
    clock_t end_time = clock();
    double execution_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Sorted Data: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    printf("Execution Time: %.6f seconds\n", execution_time);
    printf("Number of Iterations: %lld\n", iterations);

    const char *output_file_path = "sorted_data.txt";
    write_data_to_file(output_file_path, data, size);

    free(data);  // Remember to free dynamically allocated memory

    return 0;
}
