#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <n>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);

    for (int i = 0; i < n; i++)
    {
        pid_t pid = fork();

        if (pid < 0)
        {
            perror("Fork failed");
            return 1;
        }
        else if (pid == 0)
        {
            // Child process
            printf("Child process created: PID = %d, Parent PID = %d\n", getpid(), getppid());
            sleep(5); // Sleep to observe pstree
            exit(0);  // Exit child process
        }
        else
        {
            // Parent process
            printf("Parent process: PID = %d, created child PID = %d\n", getpid(), pid);
            sleep(5); // Sleep to observe pstree
        }
    }

    return 0;
}
