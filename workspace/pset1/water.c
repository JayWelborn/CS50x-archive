#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int i = 0;
    
    // Loop asks for input, and rejects negative values
    while(i <= 0)
    {
        printf("How long is your shower in minutes?\n");
        i = GetInt();
        
        // Input error checking
        if (i <= 0)
        {
            printf("That is not a likely number of minutes.\n\n");
        }
    }
    
    // Displays results
    printf("Your shower takes %d bottles of water.\n",i * 12);
}