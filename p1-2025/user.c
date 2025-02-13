/*
    Author:  January Johnson
    Date:    2/13/2025
    * user.c
    *Purpose: This file contains the main function for the user program that
    is created and controlled by the oss program.  The oss program only runs
    a specified number of user programs simultaneously.  The user process
    prints its details, waits one second, and repeats for a given number of
    times.  If the maximum number of user programs are running, the oss
    program waits for a user process to finish before starting another.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "proj1.h"

int main(int argc, char* argv[]){
    // Check for correct number of arguments.
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <iterations>\n", argv[0]);
        printHelp();
        return 1;
    }

    // Get the number of iterations from the command line.
    int iterations = atoi(argv[1]);

    // Get the parent and child process IDs.
    pid_t parent_id = getppid();
    pid_t child_id = getpid();

    // Print the process details and sleep for one second for the given number of iterations.
    for (int i = 0; i < iterations; i++) {
        printf("USER PID: %d, PPID: %d, Iterations: %d Before sleeping.\n", child_id, parent_id, iterations);
        sleep(1);
        printf("USER PID: %d, PPID: %d, Iterations: %d After sleeping.\n", child_id, parent_id, iterations);
        sleep(1);
    }

    return 0;

}


