#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>   // for fork, sleep
#include <signal.h>   // for kill
#include <sys/wait.h> // for wait
#include <time.h>     // for nanosleep

int main()
{
    pid_t pid = fork(); // create a new process

    if (pid < 0)
    {
        perror("Fork failed");
        exit(1);
    }
    else if (pid == 0)
    { // Child process
        printf("Child process created with PID: %d\n", getpid());
        sleep(10); // Simulate orphan scenario (sleep 10 seconds)
        printf("Child process (PID: %d) finished\n", getpid());
        exit(0);
    }
    else
    { // Parent process
        printf("Parent process (PID: %d) created child process (PID: %d)\n", getpid(), pid);
        sleep(2); // Let parent sleep for 2 seconds

        // Kill the child process
        printf("Parent killing child process (PID: %d)...\n", pid);
        kill(pid, SIGKILL);

        // Wait to prevent a zombie process
        wait(NULL); // Wait for the child process to terminate
        printf("Child process (PID: %d) terminated\n", pid);

        printf("Parent process (PID: %d) finished\n", getpid());
    }

    return 0;
}
