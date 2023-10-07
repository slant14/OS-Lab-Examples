#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 2

int counter = 0;

void *incrementCounter(void *threadID) {
    long tid = (long)threadID;

    for (int i = 0; i < 1000000; i++) {
        // Critical Region
        counter++;
    }

    printf("Thread %ld finished\n", tid);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;

    for (t = 0; t < NUM_THREADS; t++) {
        printf("Creating thread %ld\n", t);
        rc = pthread_create(&threads[t], NULL, incrementCounter, (void *)t);
        pthread_join(threads[t], NULL);
        if (rc) {
            printf("Error: Unable to create thread, %d\n", rc);
            exit(-1);
        }
    }

    printf("Final counter value: %d\n", counter);

    return 0;
}
