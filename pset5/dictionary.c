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
