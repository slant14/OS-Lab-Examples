#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int fd[2];  
    pid_t pid;
    char read_message[BUFFER_SIZE];


    if (argc != 2) {
        fprintf(stderr, "Wrong argument count: %s\n", argv[0]);
        exit(1);
    }

    
    if (pipe(fd) == -1) {
        perror("pipe failed");
        exit(1);
    }

    
    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    } if (pid == 0) {
        
        close(fd[1]); 

        
        read(fd[0], read_message, BUFFER_SIZE);
        printf("Child process received: %s\n", read_message);

        close(fd[0]); 
    } else{
        close(fd[0]); 
        sleep(1);

        write(fd[1], argv[1], strlen(argv[1]) + 1);
        close(fd[1]); 

        wait(NULL); 
    } 

    return 0;
}
