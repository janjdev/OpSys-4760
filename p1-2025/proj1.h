#ifndef PROJ1_H
#define PROJ1_H

#include <stdio.h>
#include <stdlib.h>

void printHelp() {
    printf("Usage: ./oss [OPTION] \n\n");
    printf("Options: \n");
    printf("\t-n the total number of `user` processes to launch.\n");
    printf("\t-s the maximum number of processes to run simultaneously.\n");
    printf("\t-t the number of iterations each `user` process will perform.\n\n");
    printf("\texample: ./oss -n 5 -s 2 -t 10\n");
    printf("\tIn this example, the program will launch 5 `user` processes,\n\trun 2 at a time, and each will iterate 10 times.\n\n");
    printf("\t-h print this help.\n\n");
}




#endif //PROJ1_H