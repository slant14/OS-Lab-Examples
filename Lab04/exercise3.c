#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_INPUT 1024         // Maximum size of the input command
#define MAX_ARGS 64            // Maximum number of arguments for a command
#define DELIMITERS " \t\r\n\a" // Delimiters for splitting input

// Function to split the input command into arguments
char **parse_input(char *input)
{
    char **args = malloc(MAX_ARGS * sizeof(char *));
    char *token;
    int position = 0;

    if (!args)
    {
        fprintf(stderr, "Allocation error\n");
        exit(EXIT_FAILURE);
    }

    // Split input using delimiters and store in args array
    token = strtok(input, DELIMITERS);
    while (token != NULL)
    {
        args[position] = token;
        position++;

        if (position >= MAX_ARGS)
        {
            fprintf(stderr, "Too many arguments\n");
            exit(EXIT_FAILURE);
        }

        token = strtok(NULL, DELIMITERS);
    }
    args[position] = NULL; // Null-terminate the argument list
    return args;
}

// Function to execute the command
void execute_command(char **args, int background)
{
    pid_t pid, wpid;
    int status;

    pid = fork();
    if (pid == 0)
    {
        // Child process: execute the command
        if (execvp(args[0], args) == -1)
        {
            perror("Error executing command");
        }
        exit(EXIT_FAILURE); // Exit if execvp fails
    }
    else if (pid < 0)
    {
        // Forking error
        perror("Error forking");
    }
    else
    {
        // Parent process
        if (!background)
        {
            // Wait for the child process if not running in background
            do
            {
                wpid = waitpid(pid, &status, WUNTRACED);
            } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        }
        else
        {
            // Background process: do not wait
            printf("Running in background, PID: %d\n", pid);
        }
    }
}

int main()
{
    char input[MAX_INPUT];
    char **args;
    int background;

    while (1)
    {
        printf("my-shell> "); // Prompt
        fflush(stdout);       // Flush stdout to ensure the prompt is displayed immediately

        // Get user input
        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            break; // Exit on EOF or error
        }

        // Check if input is empty
        if (input[0] == '\n')
        {
            continue; // Skip empty input
        }

        // Check if the command should be run in background
        background = 0;
        if (input[strlen(input) - 2] == '&')
        {
            background = 1;
            input[strlen(input) - 2] = '\0'; // Remove '&' from input
        }

        // Parse input to get arguments
        args = parse_input(input);

        // Check for built-in exit command
        if (strcmp(args[0], "exit") == 0)
        {
            free(args);
            break; // Exit the shell
        }

        // Execute the command
        execute_command(args, background);

        // Free allocated memory for arguments
        free(args);
    }

    return 0;
}
