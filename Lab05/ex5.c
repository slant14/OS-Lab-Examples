#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 1000
#define INCREMENTS_PER_THREAD 1000

// Global variable representing the counter
int counter = 0;

// Mutex to protect the counter
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Function for threads to increment the counter without protection
void *incrementWithoutMutex(void *arg)
{
    for (int i = 0; i < INCREMENTS_PER_THREAD; i++)
    {
        counter++;
    }
    return NULL;
}

// Function for threads to increment the counter with protection
void *incrementWithMutex(void *arg)
{
    for (int i = 0; i < INCREMENTS_PER_THREAD; i++)
    {
        pthread_mutex_lock(&mutex); // Lock the mutex
        counter++;
        pthread_mutex_unlock(&mutex); // Unlock the mutex
    }
    return NULL;
}

int main()
{
    pthread_t threads[NUM_THREADS];

    // Without protection (race condition)
    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_create(&threads[i], NULL, incrementWithoutMutex, NULL);
    }

    sleep(1);

    printf("Without Mutex: Final counter value = %d\n", counter);

    // Reset the counter for the next test
    counter = 0;

    // With protection (using a mutex)
    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_create(&threads[i], NULL, incrementWithMutex, NULL);
    }

    sleep(1);

    printf("With Mutex: Final counter value = %d\n", counter);

    return 0;
}
