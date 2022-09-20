#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <getopt.h>
#include <string.h>

#include "proj1.h"

int main(int argc, char* argv[])
{
    int opt, parentIter, totalLines;
    pid_t parent_id, child_id;
    char* input = "input.dat";
    char* output = "output.dat";
    char loops[100];
    FILE * fp;


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

    // Set appropiate output file name if inputfile is submitted.
    if(strcmp(input, "input.dat") != 0 && strcmp(output, "output.dat") == 0)
    {
        output = strcat(input, ".out");
    }

    // Open the file for reading
    fp = fopen(input, "r");

    // If file cannot be opened print the error and exit.
    if (fp == NULL)
    {
         perror(strcat(argv[0], ": Error: "));
        exit(EXIT_FAILURE);
    }

    // Read the first line of the file and get the total number of iterations for the parent process
    fscanf(fp, "%[^\n]", loops);
    parentIter = atoi(loops);

    //Read two lines for each child process
    totalLines = parentIter * 2;

    //Keep track of the current line to read, the line being read, and the total numbers to read
    int currentLine = 1, count = 0, nums=0;
    char file_contents[100];

    // Read the next two lines from the file and reverse the numbers
    while (count < (currentLine + 2)  && fgets(file_contents, 100, fp) != NULL)
    {
        if (count == currentLine)
        {
            nums = atoi(file_contents);
            printf("the number of Numbers is %d\n", nums);
        }
        if(count == (currentLine + 1))
        {
            int numbers[nums];
            char c[100];
            int i = 0, n =0, cc=0;
            while(file_contents[i] != '\0')
            {
                if(file_contents[i] != ' ')
                {
                     c[cc] = file_contents[i];
                     cc++;
                }
                else
                {
                    numbers[n] = atoi(c);
                    n++;
                    memset(c, 0, sizeof c);
                    cc = 0;
                }

                printf("%c", file_contents[i]);
                i++;
            }
            int p = n-1;
            while(p > -1)
            {
                printf("%d ", numbers[p]);
                p--;
            }

        }
        printf("The count is %d\n", count);
        count++;



    }






}