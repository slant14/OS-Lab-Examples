#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define n 4

void print_message() {
    pid_t pid = getpid();
    printf("Hello from [PID - %d - <%d>]\n", pid, n);
}

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed!\n");
        return 1;
    } else if (pid == 0) {
        print_message();
        printf("Child process: Going to sleep...\n");
        sleep(10);  
        printf("Child process: Woke up and exiting with error code 1\n");
        exit(1); 
    } else {
        print_message();
        printf("Parent process: Waiting for 5 seconds before killing the child...\n");
        sleep(5);

        printf("Parent process: Killing the child process...\n");
        kill(pid, SIGKILL);

        int status;
        wait(&status);

        if (WIFSIGNALED(status)) {
            printf("Child was killed by signal: %d\n", WTERMSIG(status));
        }

        printf("Parent process: Exiting normally\n");
        exit(0);  
    }

    return 0;
}
