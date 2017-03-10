#include <stdio.h>
#include <cs50.h>

int GetPosInt();
void PrintPyramid(int height);

int main(void)
{
    printf("What height do you want your pyramid?\n");
    int height = GetPosInt();
    PrintPyramid(height);
}

// This function makes sure the user's input is positive and <=23
// referenced http://www.tutorialspoint.com/cprogramming/c_functions.htm
int GetPosInt(void)
{
    int x = -1;
    while (x < 0 || x > 23)
    {
        // Tells user the requirements
        printf("Pyramid height must be positive integer \n"
                "less than or equal to 23.\n");
        x = GetInt();
        
        // Added because Check50 expected the program to exit
        // with input 0.
        if (x == 0)
        {
            exit(0);
        }
    }
    return x;
}

// This function will print a pyramid of the given height. 
// referenced http://www.tutorialspoint.com/cprogramming/c_functions.htm
void PrintPyramid(int height)
{
    int hash = 1;
    int space = (height - 1);
    
    // This loop prints the spaces and hashes based on height
    while (hash <= height)
    {
        for (int count = 0; count < space; count++)
        {
            printf(" ");
        }
        for (int count = 0; count <= hash; count++)
        {
            printf("#");
        }
        printf("\n");
        
        // incrementing hash and space for next iteration
        hash = hash + 1;
        space = space - 1;
    }
}