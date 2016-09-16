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
        printf("Usage: ./resize n infile outfile\n");
        return 1;
    }

    int factor = atoi(argv[1]);

    // ensure factor accuracy
    if (factor < 1 || factor > 100)
    {
      printf("n should be a positive number between 1 and 100\n");
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
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // determine padding for scanlines
    int paddingIn = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int paddingOut = (4 - (bi.biWidth * factor * sizeof(RGBTRIPLE)) % 4) % 4;

    int width = bi.biWidth;
    int height = bi.biHeight;

    // updating info for outfile
    bi.biWidth = width * factor;
    bi.biHeight = height * factor;
    bf.bfSize = (14 + 40) + ((bi.biWidth * abs(bi.biHeight)) * 3);
    // bi.biSize = (bi.biWidth * abs(bi.biHeight)) * 3;

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(height); i < biHeight; i++)
    {
        int comeBackPosition = ftell(inptr);
        for (int resizeH = 0; resizeH < factor; resizeH++)
        {
          fseek(inptr, comeBackPosition, SEEK_SET);
          // iterate over pixels in scanline
          for (int j = 0; j < width; j++)
          {
              // temporary storage
              RGBTRIPLE triple;

              // read RGB triple from infile
              fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

              // write RGB triple to outfile
              for (int resizeW = 0; resizeW < factor; resizeW++)
                fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
          }

          // skip over padding, if any
          fseek(inptr, paddingIn, SEEK_CUR);

          // then add it back (to demonstrate how)
          for (int k = 0; k < paddingOut; k++)
          {
              fputc(0x00, outptr);
          }
        }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
