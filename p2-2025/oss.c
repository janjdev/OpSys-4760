/*
Author: January Johnson
Date: 3/4/2025
Purpose: In this program, the parent process (`oss`) manages a simulated system scheduler
that manages child processes using a simulated system clock and Process Control Blocks (PCBs).
It controls the creation, execution, and termination of child processes while enforcing user-defined
constraints on the number of processes, runtime limits, and launch intervals. 
Example: ./oss -n 5 -s 2 -t 10
In this example, the program will launch 5 `user` processes, run 2 processes at a time, each process will
run between 1 and 10 seconds with a 100 nanoseconds between each process launch.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <time.h>

#include "proj2.h"

// Constants
#define SHM_KEY 1234 // shared memory key
#define SHM_SIZE 1024 // shared memory size
#define SHM_PERMS 0666 // shared memory permissions
#define CLOCK_KEY 1234
#define MAX_PROCS 20
#define NANO_LIMIT 1000000000 // 1 second in nanoseconds

// Shared memory structure

struct PCB {
    int occupied; // either true or false
    pid_t pid; // process id of this child
    int startSeconds; // time when it was forked
    int startNano; // time when it was forked
    };
    struct PCB processTable[20];

// Function prototypes
void sigHandler(int sig);
void cleanUp();
void printTable();
void printTime();

