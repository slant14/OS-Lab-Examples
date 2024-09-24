#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <time.h>
#include <errno.h>

#define VECTOR_SIZE 120
#define FILENAME "temp.txt"

// Function to calculate partial dot product
int calculate_partial_dot_product(int start, int end, int *u, int *v)
{
    int partial_sum = 0;
    for (int i = start; i < end; i++)
    {
        partial_sum += u[i] * v[i];
    }
    return partial_sum;
}

int main()
{
    int u[VECTOR_SIZE], v[VECTOR_SIZE];
    int n, fd;

    // Get the number of processes from user input
    printf("Enter the number of processes (n must be a power of 2): ");
    scanf("%d", &n);

    if (VECTOR_SIZE % n != 0)
    {
        fprintf(stderr, "Error: The number of processes must evenly divide the vector size.\n");
        return 1;
    }

    // Initialize random seed
    srand(time(NULL));

    // Populate vectors u and v with random values in the range [0, 99]
    for (int i = 0; i < VECTOR_SIZE; i++)
    {
        u[i] = rand() % 100;
        v[i] = rand() % 100;
    }

    // Open temp.txt for writing (create if it doesn't exist, clear if it does)
    fd = open(FILENAME, O_CREAT | O_RDWR | O_TRUNC, 0666);
    if (fd == -1)
    {
        perror("Error opening temp.txt");
        return 1;
    }

    // Calculate the chunk size each process will handle
    int chunk_size = VECTOR_SIZE / n;

    // Create n processes
    for (int i = 0; i < n; i++)
    {
        pid_t pid = fork();

        if (pid < 0)
        {
            errno = 1;
            perror("Fork failed");
            return 1;
        }
        else if (pid == 0)
        { // Child process
            int start_index = i * chunk_size;
            int end_index = start_index + chunk_size;
            int partial_dot_product = calculate_partial_dot_product(start_index, end_index, u, v);

            // Write partial result to the file
            dprintf(fd, "%d\n", partial_dot_product);

            close(fd);
            exit(0); // Exit child process after calculation
        }
    }

    // Parent process waits for all children to finish
    for (int i = 0; i < n; i++)
    {
        wait(NULL);
    }

    // Close and reopen the file for reading
    close(fd);
    fd = open(FILENAME, O_RDONLY);
    if (fd == -1)
    {
        perror("Error reopening temp.txt for reading");
        return 1;
    }

    // Aggregate the results from the file
    int final_dot_product = 0;
    char c;
    char buffer[16]; // Buffer to hold each line of the file
    int ind = 0;

    while (read(fd, &c, 1) > 0)
    {
        if (c == '\n')
        {
            buffer[ind] = '\0';
            ind = 0;
            final_dot_product += atoi(buffer);
        }
        else
        {
            buffer[ind] = c;
            ind++;
        }
    }

    // Print the final result
    printf("Final dot product: %d\n", final_dot_product);

    // Clean up
    close(fd);
    return 0;
}
