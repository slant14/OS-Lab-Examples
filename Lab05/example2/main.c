#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void* thread_function(void* arg) {
    pthread_t thread_id = pthread_self();

    printf("Thread ID: %lu is running\n", (unsigned long)thread_id);

    sleep(1);

    printf("Thread ID: %lu is terminating\n", (unsigned long)thread_id);
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;

    if (pthread_create(&thread1, NULL, thread_function, NULL)) {
        fprintf(stderr, "Error creating thread 1\n");
        return 1;
    }

    if (pthread_create(&thread2, NULL, thread_function, NULL)) {
        fprintf(stderr, "Error creating thread 2\n");
        return 1;
    }

    if (pthread_join(thread1, NULL)) {
        fprintf(stderr, "Error joining thread 1\n");
        return 2;
    }

    if (pthread_join(thread2, NULL)) {
        fprintf(stderr, "Error joining thread 2\n");
        return 2;
    }

    printf("Both threads have terminated. Main thread exiting.\n");

    return 0;
}
