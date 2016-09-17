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
    unsigned int frest;
} __attribute__((__packed__))
BLOCK;

int main(void)
{
    char* card = "card.raw";
    char title[8];

    // files counter
    int counter = 0;

    FILE* cardptr = fopen(card, "r");

    if (cardptr == NULL)
    {
        printf("Could not open %s.\n", card);
        return 2;
    }

    BLOCK bl;

    do
    {
        // (bl.f1 != 0xff && bl.f2 != 0xd8 && bl.f3 != 0xff && (bl.f4 < 0xe0 || bl.f4 > 0xef));
        fread(&bl, 512, 1, cardptr);
        printf("%ld\n", ftell(cardptr));

        // come back before a start block

    } while (fread(&bl, 512, 1, cardptr) != 1);

    // fread(&buffer, 1, 512, cardptr);

    while(counter < 2)
    {
      // creating a new jpg file
      sprintf(title, "%03d.jpg", counter);
      FILE* img = fopen(title, "a");

      if (img == NULL)
      {
          fclose(img);
          fprintf(stderr, "Could not create %s.\n", title);
          return 3;
      }

      fclose(img);

      counter++;
    }

    fclose(cardptr);
    free(bl);

    return 0;
    // FILE* outptr = fopen(title, "r");
}
