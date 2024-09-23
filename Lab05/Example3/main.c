#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int counter = 0;  

void* increment_counter(void* arg) {
    for (int i = 0; i < 1000000; i++) {
        counter++;  
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;

    if (pthread_create(&thread1, NULL, increment_counter, NULL)) {
        fprintf(stderr, "Error creating thread 1\n");
        return 1;
    }

    if (pthread_create(&thread2, NULL, increment_counter, NULL)) {
        fprintf(stderr, "Error creating thread 2\n");
        return 1;
    }

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Final counter value: %d\n", counter);

    return 0;
}
