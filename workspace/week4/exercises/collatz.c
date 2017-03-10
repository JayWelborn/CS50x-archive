#include <stdio.h>
#include <cs50.h>

int get_pos_int(void);
int Collatz(int n);

// Gets int, and runs Collatz to see if conjecture is true or false
int main(void)
{
    int number = get_pos_int();
    int count = Collatz(number);
    printf("Collatz count = %i\n", count);
}


// Ensures user provided positive number
int get_pos_int(void)
{
    int number = 0;
    while (number <= 0)
    {
        printf("Type a Postive Integer:\n");
        number = GetInt();
    }
    
    return number;
}

// Runs Collatz conjecture recursively
int Collatz(int n)
{
    if (n == 1)
        return 0;
        
    else if ((n % 2) == 0)
        return 1 + Collatz(n / 2);
        
    else
        return 1 + Collatz(3 * n + 1);
}