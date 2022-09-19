#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <getopt.h>
#include <string.h>

#include "proj1.h"

int main(int argc, char* argv[])
{
    int opt;
    pid_t parent_id, child_id;
    char* input = "input.dat";
    char* output = "output.dat";


    //Get and parse command line options.
    while((opt = getopt(argc, argv, "ho::i:")) != -1)
    {
        switch (opt)
        {
        case 'i':
            if(optarg != NULL)
            {
                input = optarg;
            }
            break;
        case 'o':
            if (optarg == NULL && optind < argc && argv[optind][0] != '-')
            {
                optarg = argv[optind++];
            }
            if(optarg != NULL)
            {
                output = optarg;
            }
            break;
        case 'h':
            printHelp();
            exit(EXIT_SUCCESS);
        default:
            printHelp();
            exit(EXIT_FAILURE);
        }
    }

    // Set appropiate output file name if input file is submitted.
    if(strcmp(input, "input.dat") != 0 && strcmp(output, "output.dat") == 0)
    {
        output = strcat(input, ".out");
    }



}