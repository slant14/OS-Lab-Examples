#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int counter = 0; 
pthread_mutex_t counter_mutex; 

void* increment_counter(void* arg) {
    for (int i = 0; i < 1000; i++) {
        pthread_mutex_lock(&counter_mutex); 
        counter++;  
        pthread_mutex_unlock(&counter_mutex);  
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[1000];  
    pthread_mutex_init(&counter_mutex, NULL);

    for (int i = 0; i < 1000; i++) {
        if (pthread_create(&threads[i], NULL, increment_counter, NULL)) {
            fprintf(stderr, "Error creating thread %d\n", i);
            return 1;
        }
    }

    for (int i = 0; i < 1000; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Final counter value (with mutex protection): %d\n", counter);
    pthread_mutex_destroy(&counter_mutex);

    return 0;
}
