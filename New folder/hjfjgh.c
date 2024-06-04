#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

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

int main() {
    // Open a file for writing execution time, iterations, and memory usage
    FILE *outputFile = fopen("output.txt", "w");

    // Array size
    int n = 10;
    int arr[] = {64, 25, 12, 22, 11, 90, 89, 33, 45, 60};

    // Record start time
    struct timeval start, end;
    gettimeofday(&start, NULL);

    // Perform bubble sort
    bubbleSort(arr, n);

    // Record end time
    gettimeofday(&end, NULL);

    // Calculate execution time
    double elapsedTime = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;

    // Write execution time to file
    fprintf(outputFile, "Execution Time: %f seconds\n", elapsedTime);

    // Write number of iterations to file
    fprintf(outputFile, "Number of Iterations: %d\n", n*(n-1)/2);

    // Get maximum resident set size (memory usage)
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    long memoryUsage = usage.ru_maxrss;

    // Write memory usage to file
    fprintf(outputFile, "Memory Usage: %ld KB\n", memoryUsage);

    // Close the file
    fclose(outputFile);

    return 0;
}
