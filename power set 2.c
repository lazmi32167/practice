#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printPowerSet(int *set, int set_size) {
    unsigned int pow_set_size = pow(2, set_size);
    int counter, j;

    for (counter = 0; counter < pow_set_size; counter++) {
        printf("{ ");
        for (j = 0; j < set_size; j++) {
            if (counter & (1 << j))
                printf("%d ", set[j]);
        }
        printf("}\n");
    }
}

int main() {
    FILE *file;
    file = fopen("power.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    int set[100];
    int set_size = 0;
    int num;

    // Read integers from file
    while (fscanf(file, "%d", &num) == 1) {
        set[set_size++] = num;
    }

    fclose(file);

    // Print the power set
    printf("Power set of the input integers:\n");
    printPowerSet(set, set_size);

    return 0;
}
