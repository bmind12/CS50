/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    unsigned int f1:8;
    unsigned int f2:8;
    unsigned int f3:8;
    unsigned int f4:8;
    unsigned int *frest;
} BLOCK;

int main(void)
{
    char* card = "card.raw";  // source file
    char title[8];            // array for img files title handling
    bool found = false;       // checking if first img were found
    int counter = 0;          // counting no. of imgs
    FILE* img;
    BLOCK bl;                 // referenceing preprocessor's struct

    // allocating memory for a block
    bl.frest = (unsigned int *) malloc(508);

    // checking if memory has been allocated
    if (bl.frest == NULL)
    {
      fprintf(stderr, "malloc failed\n");
      exit(EXIT_FAILURE);
    }

    // open an input file and check if opens
    FILE* cardptr = fopen(card, "r");

    if (cardptr == NULL)
    {
        printf("Could not open %s.\n", card);
        return 2;
    }

    // looping through the file and transferring data
    while (fread(&bl, sizeof(bl), 1, cardptr) == 1)
    {
        // check if a new jpg starts
        if  (bl.f1 == 0xff && bl.f2 == 0xd8 && bl.f3 == 0xff && \
            (bl.f4 >= 0xe0 && bl.f4 <= 0xef))
        {
            // close if another is already opened
            if (found)
              fclose(img);

            // creating a new jpg file
            sprintf(title, "%03d.jpg", counter++);
            img = fopen(title, "w");

            // checking if able to create
            if (img == NULL)
            {
                fclose(img);
                fprintf(stderr, "Could not create %s.\n", title);
                return 3;
            }

            found = true;
        }

        // check if jpg already exists
        if (found)
          fwrite(&bl, sizeof(bl), 1, img);
    }

    fclose(cardptr);
    free(bl.frest);

    return 0;
}
