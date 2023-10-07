#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Function to be executed by each thread
void *threadFunction(void *arg)
{
    int threadID = *((int *)arg); // Cast the argument to an integer

    // Display a message containing the thread ID
    printf("Thread %d: Hello from thread %d!\n", threadID, threadID);

    // Exit the thread
    pthread_exit(NULL);
}

int main()
{
    pthread_t thread1, thread2;
    int id1 = 1, id2 = 2; // Unique IDs for the threads

    // Create thread 1
    pthread_create(&thread1, NULL, threadFunction, &id1);

    // Create thread 2
    pthread_create(&thread2, NULL, threadFunction, &id2);

    sleep(1);

    printf("Both threads have terminated.\n");

    return 0;
}
