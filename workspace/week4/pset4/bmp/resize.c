/**
 * copy.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./copy n infile outfile\n");
        return 1;
    }
    
    int ratio = atoi(argv[1]);
    
    if (ratio < 1)
    {
        printf("Usage: ./copy n infile outfile\n");
        return 1;
    }
    else if (ratio >= 100)
    {
        printf("Resize is too large.\n");
        return 1;
    }
    

    // remember filenames
    char* infile = argv[2];
    char* outfile = argv[3];

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER inbf;
    fread(&inbf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER inbi;
    fread(&inbi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (inbf.bfType != 0x4d42 || inbf.bfOffBits != 54 || inbi.biSize != 40 || 
        inbi.biBitCount != 24 || inbi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    
    // change outfile Height/Width
    BITMAPINFOHEADER outbi = inbi;
    outbi.biHeight = outbi.biHeight * ratio;
    outbi.biWidth = outbi.biWidth * ratio;
    
    // setting variables for SizeImage
    int outpadding = (4 - (outbi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int area = (abs(outbi.biHeight) * outbi.biWidth * sizeof(RGBTRIPLE));
    
    // set new biSizeImage
    outbi.biSizeImage = area + (abs(outbi.biHeight) * outpadding);
    
    // change outfile file header bfSize
    BITMAPFILEHEADER outbf = inbf;
    int info_size = sizeof(BITMAPINFOHEADER);
    int header_size = sizeof(BITMAPFILEHEADER);
    outbf.bfSize = outbi.biSizeImage + info_size + header_size;
    
    // write outfile's BITMAPFILEHEADER
    fwrite(&outbf, sizeof(BITMAPFILEHEADER), 1, outptr);
    
    // write outfile's BITMAPINFOHEADER
    fwrite(&outbi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // determine padding for scanlines
    int inpadding =  (4 - (inbi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    // determine width of infile for scanning
    int inWidth = 0 - inbi.biWidth * sizeof(RGBTRIPLE);

    // iterate over infile's scanlines
    for (int i = 1, outbiHeight = abs(outbi.biHeight); i <= outbiHeight; i++)
    {
        // scans and prints each row
        for (int j = 0; j < inbi.biWidth; j++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            // writes each pixel (ratio) times
            for (int x = 0; x < ratio; x++)
            {
                fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
            }
        }
        // pad each line
        for (int k = 0; k < outpadding; k++)
        {
            fputc(0x00, outptr);
        }
        // skip infile padding if moving to next line
        if (i % ratio == 0)
        {
            fseek(inptr, inpadding, SEEK_CUR);
        }
        // repeat until each line is scanned and printed (ratio) times.
        else
        {
            fseek(inptr, inWidth, SEEK_CUR);
        }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // finally done.
    return 0;
}
