/*
    Author:  January Johnson
    Date:    3/4/2025
    Purpose: This file contains the main function for the worker program that
    is created and controlled by the oss program.  The oss program only runs
    a specified number of worker programs simultaneously.  When a worker process begins,
    it prints its details consisting of the process id, parent process id, the current clock seconds, and nanoseconds.
    and its stop time in seconds and nanoseconds.  The worker program then checks the clock and outputs the pid, parent pid,
    current time, and stop time every 1 second (1000000000 nanoseconds) until stop time is reached.  The worker program then
    exits and the oss program can start another worker program. If the maximum number of worker programs are running, the oss
    program waits for a user process to finish before starting another.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>