#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int counter = 0;  

void* increment_counter(void* arg) {
    for (int i = 0; i < 1000; i++) {
        counter++; 
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[1000];  

    for (int i = 0; i < 1000; i++) {
        if (pthread_create(&threads[i], NULL, increment_counter, NULL)) {
            fprintf(stderr, "Error creating thread %d\n", i);
            return 1;
        }
    }

    for (int i = 0; i < 1000; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Final counter value (with race condition): %d\n", counter);

    return 0;
}
