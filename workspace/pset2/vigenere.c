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
        printf("Need exactly 1 key.\n");
        return 1;
    }
    
    // Converts argv into string key_word,
    // and gets its length for reference
    string key_word = argv[1];
    int key_length = strlen(key_word);
    
    // verifies that key_word has only letters
    for (int i = 0; i < key_length; i++)
    {
        int value = key_word[i];
        if (value < 65 || value > 122)
        {
            printf("Invalid input\n");
            exit(1);
        }
        if (90 < value && value < 97)
        {
            printf("Invalid input\n");
            exit(1);
        }
    }
    
    // Gets string from user, iterates through for loop
    // to move all letters by the key value
    string message = GetString();
    for (int i = 0, count = -1; i < strlen(message); i++)
    {
        int letter = message[i];
        int key = 0;
        
        // Check to make sure the character being encrypted is a letter
        if (65 <= letter && letter <= 90)
        {
            count = (count + 1) % key_length;
            key = key_word[count];
        }
        else if (97 <= letter && letter <= 122)
        {
            count = (count + 1) % key_length;
            key = key_word[count];
        }
        else
        {
            key = 0;
        }
        
        // Shifts key value from ascii value to letter place in alphabed
        if (65 <= key && key <= 90)
        {
            key = key - 65;
        }
        if (97 <= key && key <= 122)
        {
            key = key - 97;
        }
        
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