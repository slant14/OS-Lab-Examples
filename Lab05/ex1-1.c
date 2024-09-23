#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
    int fd[2]; // Array to hold the two ends of the pipe (fd[0] for reading, fd[1] for writing)
    pid_t pid;
    char write_message[] = "Test message from the parent process to the child process!";
    char read_message[BUFFER_SIZE];

    
    if (pipe(fd) == -1) {
        perror("pipe failed");
        exit(1);
    }

    
    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
        
    } if (pid  == 0) { // child process
        close(fd[1]); // Close the write end of the pipe in the child

        // Read from the pipe
        read(fd[0], read_message, BUFFER_SIZE);
        printf("Child process read: %s\n", read_message);

        close(fd[0]); // Close the read end of the pipe
    } else { // parent process

        close(fd[0]); // Close the read end of the pipe in the parent

        // Write to the pipe
        write(fd[1], write_message, strlen(write_message) + 1);

        close(fd[1]);

        wait(NULL); 
    }

    return 0;
}
