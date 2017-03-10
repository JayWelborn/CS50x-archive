#include <stdio.h>
#include <cs50.h>

double GetLength(int side);
int CheckLength(double side_a, double side_b, double side_c);

// Tells user what program does, calls other functions
// Based on 1/0 return from CheckLength, prints True or False
int main(void)
{
    printf("This Program will test to see if three\n"
           "numbers can be the three sides of a\n"
           "triangle.\n");
    
    // Gets Length of all three sides       
    double side_one = GetLength(1);
    double side_two = GetLength(2);
    double side_three = GetLength(3);
    
    // Passes lengths to CheckLength as arguments
    // Receives return of 1 for true, 0 for false
    int check = CheckLength(side_one, side_two, side_three);
    
    // Checks true/false value and prints accordingly
    if (check == 0)
    {
        printf ("False\n");
    }
    else if (check == 1)
    {
        printf("True\n");
    }
    return 0;
}

// Gets length for side of a triangle. Accepts positive doubles.
double GetLength(int side)
{
    double length = 0;
    while (length <= 0)
    {
        printf("Length of side %i\n", side);
        length = GetDouble();
        
        // Rejects 0 or negative values
        if (length <= 0)
        {
            printf("Invalid Length\n");
        }
    }
    return length;
}

// Compares lengths of sides. Only returns true
// if all conditions are met.
int CheckLength(double side_a, double side_b, double side_c)
{
    // Checks all three conditions at once.
    // Referenced url below for syntax.
    // http://stackoverflow.com/questions/253030/ ...
    // best-way-to-format-if-statement-with-multiple-conditions
    if (side_a + side_b > side_c && 
        side_a + side_c > side_b && 
        side_c + side_b > side_a)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}