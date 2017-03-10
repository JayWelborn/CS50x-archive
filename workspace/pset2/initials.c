#include <stdio.h>
#include <cs50.h>
#include <string.h>

int Capitalize(int letter);

int main(void)
{
    string name = GetString();
    
    // Loop picks out characters after spaces,
    // Capitalizes them if needed,
    // and prints them
    for(int i = 0; i < strlen(name); i++)
    {
        int ascii = name[i];
        
        // Ensures first character is capitalized
        if (i == 0)
        {
            ascii = Capitalize(ascii);
            printf("%c", ascii);
        }
        
        // Tests if a character is a space,
        // seeks next character, capitalizes,
        // and prints it
        if (ascii == 32)
        {
            ascii = name[i + 1];
            ascii = Capitalize(ascii);
            printf("%c", ascii);
        }
    }
    printf("\n");
}

// Function tests is a letter is capital. If it's not
// it capitalizes it.
int Capitalize(int letter)
{
    if (letter >= 97)
    {
        letter = letter - 32;
    }
    return letter;
}