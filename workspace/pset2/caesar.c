#include <stdio.h>
#include <cs50.h>
#include <string.h>

int Encrypt(int letter, int key);

int main(int argc, string argv[])
{
    // Gets key from command line, and checks to ensure
    // exactly one argument was entered.
    if (argc != 2)
    {
        printf("Need a key.\n");
        return 1;
    }
    
    // Converts argv[] into an integer.
    int key = atoi(argv[1]);
    key = key % 26;
    
    // Rejects non-positive integers, strings, etc.
    if (key <= 0)
    {
        printf("Only one positive integer, please.\n");
        return 1;
    }
    
    // ROT26, twice as secure? I think not!
    else if (key % 26 == 0)
    {
        printf("Multiples of 26 don't do any good.\n");
        return 1;
    }
    
    // Gets string from user, iterates through for loop
    // to move all letters by the key value
    string message = GetString();
    for (int i = 0; i < strlen(message); i++)
    {
        int letter = message[i];
        letter = Encrypt(letter, key);
        printf("%c", letter);
    }
    printf("\n");
}

// Function shifts letters based on key value
int Encrypt(int letter, int key)
{
    // Handles upper case ascii values
    if (65 <= letter && letter <= 90)
    {
        letter = letter + key;
        if (letter > 90)
        {
            letter = letter - 26;
        }
        return letter;
    }
    
    // Handles lower case ascii values
    else if (97 <= letter && letter <= 122)
    {
        letter = letter + key;
        if (letter > 122)
        {
            letter = letter - 26;
        }
        return letter;
    }
    
    // Leaves other characters alone
    else
    {
        return letter;
    }
}