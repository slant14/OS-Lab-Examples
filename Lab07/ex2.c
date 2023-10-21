#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

    extern char etext;
    printf("End address of the data segment: %p\n", &etext);

    int N;
    int *array;


    printf("Enter the value of N: ");
    scanf("%d", &N);


    if (N <= 0) {
        printf("N should be a positive integer.\n");
        return 1; 
    }


    array = (int *)malloc(N * sizeof(int));


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

    free(array);

    int *new_heap = sbrk(N * sizeof(int));
    if (new_heap == (void *)-1) {
        printf("Failed to expand the heap segment.\n");
    } else {
        printf("Heap segment expanded successfully.\n");
    }


    return 0; // Exit with a success code
}
