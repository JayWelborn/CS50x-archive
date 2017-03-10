/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>
#include "helpers.h"

int BinarySearch(int value, int values[], int upper, int lower, int middle);

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int size)
{
    // Checks needle value, calls Binary Search function
    if (value <= 0)
    {
        printf("Needle can't be negative.\n");
        return false;
    }
    else
    {
        int lower = 0;
        int upper = size - 1;
        int middle = upper / 2;
        
        // Binary search loop
        while (lower <= upper)
        {
            if (value == values[middle])
            {
                return true;
            }
            else if (value < values[middle])
            {
                upper = middle - 1;
                middle = (upper + lower) / 2;
            }
            else if (value > values[middle])
            {
                lower = middle + 1;
                middle = (upper + lower) / 2;
            }
        }
    }
    return false;
}



/**
 * Sorts array of n values.
 */
void sort(int values[], int size)
{
    // Nested loops bubble sort the list.
    // If the number of swaps is 0 on an iteration, the operation is complete.
    int swap;
    int count = 0;
    do
    {
        swap = 0;
        
        // Inner loop iterates through the list making 1 round of swaps.
        for (int i = count; i < size - 1; i++)
        {
            int current = values[i];
            int next = values[i + 1];
            if (current > next)
            {
                values[i] = next;
                values[i + 1] = current;
                swap += 1;
            }
            else
            {
                continue;
            }
        }
        count += 1;
    }
    while (swap > 0);
    
    for (int i = 0; i < size; i ++)
    {
        printf("%d\n", values[i]);
    }
    
    return;
}