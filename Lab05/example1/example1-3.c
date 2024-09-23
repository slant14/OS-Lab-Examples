#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int pipe1[2];  // Pipe from parent to child
    int pipe2[2];  // Pipe from child to parent
    pid_t pid;
    char read_message[BUFFER_SIZE];
    int message_length;

    if (argc != 2) {
        fprintf(stderr, "Wrong argument countt: %s\n", argv[0]);
        exit(1);
    }

    if (pipe(pipe1) == -1) {
        perror("pipe1 failed");
        exit(1);
    }

    if (pipe(pipe2) == -1) {
        perror("pipe2 failed");
        exit(1);
    }

    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    } if (pid == 0) {

        close(pipe1[1]); 
        close(pipe2[0]);

        read(pipe1[0], read_message, BUFFER_SIZE);
        printf("Child received: %s\n", read_message);

        message_length = strlen(read_message);

        write(pipe2[1], &message_length, sizeof(message_length));
        close(pipe2[1]); 
        close(pipe1[0]); 
        
    } else {
        close(pipe1[0]); 
        close(pipe2[1]); 

        write(pipe1[1], argv[1], strlen(argv[1]) + 1); 
        close(pipe1[1]); 

        read(pipe2[0], &message_length, sizeof(message_length));
        printf("Parent received message length: %d\n", message_length);
        close(pipe2[0]); 

        wait(NULL); 

    } 
    return 0;
}
