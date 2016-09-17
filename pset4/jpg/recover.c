/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */

#include <stdio.h>

typedef struct
{
    unsigned int f1:8;
    unsigned int f2:8;
    unsigned int f3:8;
    unsigned int f4:8;
    unsigned int fn;
} __attribute__((__packed__))
BLOCK;

int main(void)
{
    // remember filenames
    char* card = "card.raw";

    // creating buffer
    // char buffer[512];
    char* title;

    // files counter
    int counter = 0;

    FILE* cardptr = fopen(card, "r");

    if (cardptr == NULL)
    {
        printf("Could not open %s.\n", card);
        return 2;
    }

    while(!feof(cardptr) && counter < 10)
    {
      // fread(&title, 512, 1, inptr);

      // creating a new jpg file
      sprintf(title, "%03d.jpg", counter);
      FILE* img = fopen(title, "a");

      if (img == NULL)
      {
          fclose(img);
          fprintf(stderr, "Could not create %s.\n", img);
          return 3;
      }

      fclose(img);

      // printf("%d: ", counter);
      // printf("%#x, %#x, %#x, %#x, %#x\n", read[0], read[1], read[2], read[3], read[4]);
      counter++;
    }

    fclose(cardptr);
    // FILE* outptr = fopen(title, "r");
}
