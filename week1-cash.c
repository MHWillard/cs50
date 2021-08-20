//Here's the cash problem set. Obviously a function can make this more efficient and better styled but I decided to stick within the rules of what the course teaches that week.

#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void) {
    int coins = 0;
    float changeOwed;

    do
    {
        changeOwed = get_float("Change owed: ");
    }
    while (changeOwed <= 0);

    int cents = round(changeOwed * 100);
    float currentChange = cents;

    while (currentChange >= 25)
    {
        currentChange -= 25;
        coins++;
    }

    while (currentChange >= 10 && currentChange < 25)
    {
        currentChange -= 10;
        coins++;
    }

        while (currentChange >= 05 && currentChange < 10)
    {
        currentChange -= 05;
        coins++;
    }

        while (currentChange > 0 && currentChange < 05)
    {
        currentChange -= 01;
        coins++;
    }

    printf("Coins: %i\n", coins);