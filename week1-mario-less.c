//Less comfortable version of Mario problem. This was done in CS50's IDE (ide.cs50.io) so that's where the cs50.h package comes in. Very challenging! Should've used functions.

#include <stdio.h>
#include <cs50.h>

int main(void) {
    int height;

    //loop request for input until it matches. Declare height BEFORE asking for the input.
    do
    {
        height = get_int("Height: ");
    }
    while (height <= 1 || height >= 8);

    //set width of row.
    int width = 0;

    //loop over number indicated by height variable.
    for (int i = 0; i < height; i++) {

        //get the number of spaces needed to drop spaces (originally periods)
        int period = height - i;

        //print spaces
        for (int y = 0; y < period; y++) {
            printf(" ");
        }

        //print hashes based on actual width of row.
        for (int g = 0; g <= width; g++) {
            printf("#");
        }

        printf("\n");
        width++;
    }
}
