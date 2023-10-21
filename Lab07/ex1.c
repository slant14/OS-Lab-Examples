#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;

    printf("Enter the value of N: ");
    scanf("%d", &N);

    if (N <= 0) {
        printf("N should be a positive integer.\n");
        return 1; 
    }


    int *array = (int *)malloc(N * sizeof(int));

    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1; 
    }

    for (int i = 0; i < N; i++) {
        array[i] = i;
    }


    printf("Array values: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");


    free(array); //deallocate

    return 0; 
}
