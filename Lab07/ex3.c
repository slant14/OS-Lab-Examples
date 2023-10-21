#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>

int main() {

    size_t size = 100 * 1024 * 1024;


    char *mem = (char *)mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

    if (mem == MAP_FAILED) {
        perror("mmap");
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

    // Unmap the allocated region
    if (munmap(mem, size) == -1) {
        perror("munmap");
        return 1;
    }

    return 0;
}
