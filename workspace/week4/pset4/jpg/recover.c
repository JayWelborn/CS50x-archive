/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
  
#include <stdio.h>
#include <cs50.h>
#include <stdint.h>

#define JPGSIZE 512
typedef uint8_t BYTE;

bool is_jpg(BYTE buffer[]);

int main(void)
{
    // set counter/ character array for file name
    int file_num = 0;
    char title[8];
    
    // set file pointer for writing to NULL
    FILE* img = NULL;
    
    // make buffer as an array of bytes
    // reference:
    // stackoverflow.com/questions/22240267/how-to-store-byte-arrays-in-c
    BYTE buffer[JPGSIZE];
    
    // open the card for reading
    FILE* inptr = fopen("card.raw", "r");
    if (inptr == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }
    
    // loop to read/write the files in blocks of 512 bytes
    while (true)
    {
        // read 512 bytes into buffer
        fread(&buffer, JPGSIZE, 1, inptr);
        // end when seeker is at end of file
        if (feof(inptr))
        {
            break;
        }
        // checks if block is the start of a jpeg
        if (is_jpg(buffer))
        {
             // closes the previous file if open
            if (img != NULL)
            {
                fclose(img);
            }
            // increment file number, make new file in directory
            sprintf(title, "%03d.jpg", file_num);
            file_num += 1;
            
            // open new file for editing, write data
            img = fopen(title, "a");
            if (img == NULL)
            {
                perror("Error: ");
                printf("\n");
                exit(1);
            }
            fwrite(&buffer, 1, sizeof(buffer), img);
        }
        // writes buffer to current file if one is open
        else if (img != NULL)
        {
            fwrite(&buffer, 1, sizeof(buffer), img);
        }
    }
    fclose(inptr);
    fclose(img);
    return 0;
}

bool is_jpg(BYTE buffer[])
{
    BYTE jpg_first_3[] = {0xff, 0xd8, 0xff};
    BYTE jpg_4[] = {0xe0, 0xe1, 0xe2, 0xe3, 0xe4,
                    0xe5, 0xe6, 0xe7, 0xe8, 0xe9,
                    0xea, 0xeb, 0xec, 0xed, 0xef};
    // returns false if first 3 don't match
    for (int i = 0; i < 3; i++)
    {
        if (buffer[i] != jpg_first_3[i])
        {
            return false;
        }
    }
    // returns true if last one matches (won't get here unless 1st 3 also match)
    for (int i = 0; i < 16; i++)
    {
        if (buffer[3] == jpg_4[i])
        {
            return true;
        }
    }
    // this shouldn't happen
    return false;
}