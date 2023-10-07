#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <message>\n", argv[0]);
        return 1;
    }

    int pipe_fd[2];
    pipe(pipe_fd);

    pid_t pid = fork();

    if (pid == 0)
    {
        // Child process
        close(pipe_fd[1]); // Close the write end of the pipe in the child process

        char message[256];
        char ch;
        int i = 0;

        // Read the message char by char until there's a read error
        while (read(pipe_fd[0], &ch, sizeof(char)) > 0 && i < sizeof(message) - 1)
        {
            message[i++] = ch;
        }
        message[i] = '\0'; // Null-terminate the message

        close(pipe_fd[0]); // Close the read end of the pipe in the child process

        printf("Child Process Received: %s\n", message);
    }
    else
    {
        // Parent process
        close(pipe_fd[0]); // Close the read end of the pipe in the parent process

        char *message = argv[1];

        // Send the message char by char
        for (int i = 0; i < strlen(message); i++)
        {
            if (write(pipe_fd[1], &message[i], sizeof(char)) == -1)
            {
                perror("write");
                return 1;
            }
        }

        close(pipe_fd[1]); // Close the write end of the pipe in the parent process
    }

    return 0;
}
