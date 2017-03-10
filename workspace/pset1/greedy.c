#include <stdio.h>
#include <cs50.h>
#include <math.h>

int GetChange();
int CountCoins(int cents);

int main(void)
{
    int cents = GetChange();
    int coins = CountCoins(cents); 
    printf( "%i\n", coins);
}

// This function gets the user to specify amount of change owed,
// and converts that into an integer representing the number of
// cents owed.

// referenced http://www.tutorialspoint.com/cprogramming/c_functions.htm
int GetChange(void)
{
    float change = 0;
    while (change <= 0)
    {
        printf("How much change are you owed?\n");
        change = GetFloat();
        
        // error checking.
        
        if (change <= 0)
        {
            printf("That's not a number change can be.\n");
        }
    }

// https://cs50.harvard.edu/resources/cppreference.com/stdmath/round.html
    int cents = round(change * 100);
    return cents;
}

// This function determines the number of coins it takes
// to make correct change.

int CountCoins(int cents)
{
    int coins = 0;
    while (cents >= 25)
    {
        cents = cents - 25;
        coins = coins + 1;
    }
    while (cents >= 10)
    {
        cents = cents - 10;
        coins = coins + 1;
    }
    while (cents >= 5)
    {
        cents = cents - 5;
        coins = coins + 1;
    }
    while (cents >= 1)
    {
        cents = cents - 1;
        coins = coins + 1;
    }
    return coins;
}