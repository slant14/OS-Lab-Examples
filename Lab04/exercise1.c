#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>   // for clock(t)
#include <stdlib.h> // for exit()

void print_process_info(clock_t start_time, const char *process_name)
{
    clock_t end_time = clock();                                                      // get end time
    double execution_time = (double)(end_time - start_time) * 1000 / CLOCKS_PER_SEC; // convert to milliseconds

    // Print process information
    printf("Process: %s\n", process_name);
    printf("PID: %d, PPID: %d\n", getpid(), getppid());
    printf("Execution time: %.2f ms\n\n", execution_time);
}

int main()
{
    clock_t start_time_main = clock(); // start time for main process

    pid_t pid1, pid2;

    // First fork to create process 1
    pid1 = fork();

    if (pid1 == 0)
    {
        // Child process 1
        clock_t start_time_p1 = clock(); // start time for process 1
        print_process_info(start_time_p1, "Child Process 1");
        exit(0); // exit child process 1
    }

    // Second fork to create process 2
    pid2 = fork();

    if (pid2 == 0)
    {
        // Child process 2
        clock_t start_time_p2 = clock(); // start time for process 2
        print_process_info(start_time_p2, "Child Process 2");
        exit(0); // exit child process 2
    }

    // Main process
    print_process_info(start_time_main, "Main Process");

    // Wait for child processes to finish (optional, can use wait())
    sleep(1);

    return 0;
}
