//Week 1 lab to see how many years a population of llamas will take to reach an end amount. Each year, given n llamas, n /3 llamas are born, and n /4 llamas die.

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int startSize;
    int endSize;
    int currentSize = 0;
    int born;
    int died;
    int years = 0;

    // TODO: Prompt for start size
    do
    {
        startSize = get_int("Start Size: ");
    }
    while (startSize <= 9);

    // TODO: Prompt for end size
    do
    {
        endSize = get_int("End Size: ");
    }
    while (endSize < startSize);

    // TODO: Calculate number of years until we reach threshold
    currentSize = startSize;

    while (currentSize < endSize)
    {
        born = (currentSize / 3);
        died = (currentSize / 4);
        currentSize += (born - died);
        years++;
    }

    // TODO: Print number of years
    printf("Years: %i\n", years);

}