#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

    size_t size = 100 * 1024 * 1024;


    char *mem = (char *)sbrk(size);

    if (mem == (void *)-1) {
        perror("sbrk");
        return 1;
    }


    for (size_t i = 0; i < size; i++) {
        mem[i] = rand();
    }

    for (size_t i = 0; i < size; i++) {
        if (mem[i] % 11 == 0) {
            printf("Divisible by 11 at location %zu: %d\n", i, mem[i]);
        }
    }

    return 0;
}
