/*
Implement a program called recover that recovers JPEGs from a forensic image.

Implement your program in a file called recover.c in a directory called recover.
Your program should accept exactly one command-line argument, the name of a forensic image from which to recover JPEGs.
If your program is not executed with exactly one command-line argument, it should remind the user of correct usage, and main should return 1.
If the forensic image cannot be opened for reading, your program should inform the user as much, and main should return 1.
The files you generate should each be named ###.jpg, where ### is a three-digit decimal number, starting with 000 for the first image and counting up.
Your program, if it uses malloc, must not leak any memory.
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

//ask for file argument: asking for card.raw: ./recover -card
////file name: arg 0, actual arg: arg 1
//if argument isn't present: ask for one, return 1
//if file can't be opened: inform, return 1

if (argc != 2) {
    printf("Usage: ./recover filename.raw\n");
    printf("Filename is the name of a .raw file.\n");
    return 1;
}

//assign argument to pointer for file
char *infile = argv[1];

    //open file with name of argument
    FILE *file = fopen(infile, "r");
    if (file == NULL) {
        printf("File not found.\n");
        return 1;
    }
    printf("File opened!\n");
    fclose(file);
    printf("File closed!\n");

/*
//open raw file
//do this until EOF:

//load 512 bytes into buffer
//check first four bytes
//if doesn't match JPEG signature, move to next block and load that into buffer, repeat

//if matches JPEG signature:
//create open output file
//copy header and bit into output each bit at a time
////each bit: check for a zero, if so: read to the end of the block and mark end of JPEG as true
////otherwise: load next block into buffer and check for header; if that doesn't apply, iterate through this block like normal and continue checking for 0

FUNCTIONS
check_for_header: check start of loaded buffer block to see if JPEG signature exists and return true/false
check_for_slack: check buffer block for slack space 0s at end of block and return true/false
iterate_block: read each bit in buffer and push it to output file

*/

//at the end: fclose output for each file
//end with fclose for raw

}