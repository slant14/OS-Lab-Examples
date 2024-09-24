#include <stdio.h>
#include <unistd.h>    // for fork() and getpid()
#include <stdlib.h>    // for exit()
#include <sys/types.h> // for pid_t
#include <signal.h>    // for kill()

int main()
{
    int n = 4; // Declare variable n

    pid_t pid = fork(); // Create a new process using fork

    if (pid < 0)
    {
        // Fork failed
        perror("Fork failed");
        exit(1);
    }
    else if (pid == 0)
    {
        // This is the child process
        printf("Hello from [%d - %d - %p] (Child)\n", getpid(), n, (void *)&n);

        // Error exit for child
        exit(1);
    }
    else
    {
        // This is the parent process
        printf("Hello from [%d - %d - %p] (Parent)\n", getpid(), n, (void *)&n);

        // Optionally, the parent can kill the child process
        // Uncomment the following lines to terminate the child process
        // kill(pid, SIGKILL);

        // Normal exit for parent
        exit(0);
    }

    return 0;
}
