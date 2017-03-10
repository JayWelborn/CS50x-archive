#include <stdio.h>
#include <cs50.h>

int GetPosInt();

// Will build an array of size n with each entry
// equal to its index.
int main(void)
{
    printf("Size of array to build:\n");
    
    // Calls function to ensure array size is
    // a positive integer
    int size = GetPosInt();
    
    // Defines array as having (size) spaces
    int array[size];

    // Adds integers to the array
    for (int i = 0; i < size; i++)
    {
        array[i] = i;
    }
    
    // Prints contents of the array
    for (int i = 0; i < size; i++)
    { 
        printf("%d\n", array[i]);
    }
    
    // To avoid error statement
    return 0;
}

int GetPosInt(void)
{
    int integer = 0;
    
    // Gets integer and checks to ensure it's positive
    while (integer <= 0)
    {    
        integer = GetInt();
        if (integer <= 0)
        {
            printf("Needs to be positive.\n");
        }
    }
    printf("\n");
    return integer;
}