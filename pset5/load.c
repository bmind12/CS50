#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "dictionary.h"

typedef struct node
{
  bool is_word;
  struct node* paths[27];
}
node;

node* root;

int main(void)
{
    char word[LENGTH+1];
    int index = 0;

    // Openning the dictionary
    FILE* fd = fopen("dictionaries/large", "r");

    // Check if could not open
    if (fd == NULL)
    {
        printf("Could not open dictionaries/large.\n");
        unload();
        return false;
    }

    // Root pointer to initial structure 
    root = (node*) malloc(sizeof(node));

    // Scanning the dictionary
    for (int c = fgetc(fd); c != EOF; c = fgetc(fd))
    {
        if (c != '\n')
        {
            word[index] = c;
            index++;
        }
        else
        {
            if (node->)
            node = (node*) malloc(sizeof(node))
            index = 0
        }
    }

    return false;
}
