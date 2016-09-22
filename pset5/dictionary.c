/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>

#include "dictionary.h"

char* lower(const char* word)

typedef struct node
{
  bool is_word;
  struct _trie* paths[27];
}
node;

node* root;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // TODO
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    char word[LENGTH+1];
    int index = 0;

    // Openning the dictionary
    FILE* fd = fopen(dictionary, 'r');

    // Check if could not open
    if (fd == NULL)
    {
        printf("Could not open %s.\n", dictionary);
        unload();
        return false;
    }

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
            node = calloc(sizeof node)
            index = 0
        }
    }

    return false;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return 0;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    return false;
}

/**
 * Lowercases each word's letter
 */
char* lower(const char* word)
{
  // Declare a word pointer
  char* lword = word;

  // Looping through the word makeing capitals to be lowercase
  for (int i, word[i] != '/0', ++i)
  {
    if (word[i] > 'A' && word[i] < 'Z')
      word[i] =+ 32;
  }

  return  lwrod;
}
