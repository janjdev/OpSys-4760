/*
Author: January Johnson
Date: 2/13/2025
Purpose: In this program, the parent process (`oss`) controls one or more child processes (`user`).  
Each `user` process prints its details, waits one second, and repeats for a specified number of times.  The `oss` process creates and
manages the `user` processes, making sure only a certain number run at once.  It waits for a process to
finish before starting another.  
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <getopt.h>
#include <string.h>

#include "proj1.h"

int main(int argc, char* argv[])
{
    // Variable to store command-line options
    int opt;

    // Number of processes to create
    int processes;

    // Number of simultaneous processes to run
    int simultaneous;

    // Number of iterations for each process
    int iterations;

    // Number of launched processes
    int launched = 0;

    // Number of active processes
    int active = 0;


    //Get and parse command line options.
    while((opt = getopt(argc, argv, "hn:s:t:")) != -1)
    {
        switch (opt)
        {
        case 'n':
            if(optarg != NULL)
            {
                processes = atoi(optarg);
            }
            else
            {
                printf("No argument provided for -n.  Using default value of 5.\n");
                processes = 5;
            }
            break;
        case 's':
            if(optarg != NULL)
            {
                simultaneous = atoi(optarg);
            }
            else
            {
                printf("No argument provided for -s.  Using default value of 2.\n");
                simultaneous = 2;
            }
            break;
        case 't':
            if(optarg != NULL)
            {
                iterations = atoi(optarg);
            }
            else
            {
                printf("No argument provided for -t.  Using default value of 10.\n");
                iterations = 5;
            }
            break;
        case 'h':
            printHelp();
            exit(EXIT_SUCCESS);
        default:
        printf("Invalid option.  Please use -h for help.\n");
            printHelp();
            exit(EXIT_FAILURE);
        }
    }

    // Verify that the number of processes is greater than the number of simultaneous processes.
    if(processes < simultaneous)
    {
        printf("The number of processes must be greater than the number of simultaneous processes.\n");
        printHelp();
        exit(EXIT_FAILURE);
    }

    // Verify that the number of processes, simultaneous processes, and iterations are positive.
    if (processes <= 0 || simultaneous <= 0 || iterations <= 0) {
        fprintf(stderr, "Invalid arguments. Please provide positive integers for -n, -s, and -t.\n");
        printHelp();
        return 1;
    }

    // Create the specified number of processes.
    while (launched < processes ) {

        // If the number of active processes < the number of simultaneous processes, continue.
        if (active < simultaneous) {

            // Fork a new process.
            pid_t pid = fork();

            // If the fork fails, print an error message and exit.
            if (pid < 0) {
                perror("fork");
                exit(EXIT_FAILURE);
            }
            // If the fork is successful, execute the user program.
            if (pid == 0) {
                
                // Create a char var to pass the number of iterations to the user 
                char iterations_str[10];
                sprintf(iterations_str, "%d", iterations);

                // Run the user main function and pass the iteration string.
                execl("./user", "./user", iterations_str, NULL);
                perror("execl");  // If execl fails
                exit(EXIT_FAILURE);

            }
             // Increment the number of active processes and launched processes.
            launched++;
            active++;
        }
        if (active >= simultaneous) {
            // Wait for a child process to finish to free up a slot for a new process.
            int status;
            pid_t finished_pid = wait(&status);
            if (finished_pid > 0) {
                active--;  // Reduce active process count
            }
        }
        
    }

    while (active > 0) {
        // Wait for all child processes to finish.
        int status;
        pid_t finished_pid = wait(&status);
        if (finished_pid > 0) {
            active--;  // Reduce active process count
        }
    }    
   
}