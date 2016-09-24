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
  struct node* paths[27];
}
node;

node* root;

int CHARTONUM = 97;

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
  char cchar;
  char word[LENGTH+1];
  int j = 0;
  int index = 0;
  int nodes_count = 2;


  // Openning the dictionary
  FILE* fd = fopen("dictionaries/large", "r");

  // Check if could not open
  if (fd == NULL)
  {
      printf("Could not open dictionaries/large.\n");
      unload();
      return false;
  }

  // Initial structure and checking
  node* node1 = malloc(sizeof(node));

  if (node1 == NULL)
  {
      printf("Out of heap memory\n");
      return false;
  }

  // Root pointer to initial structure
  root = node1;

  // NULLing array
  for (int i = 0; i < 27; i++)
    root->paths[i] = NULL;

  // Defining and linking a crawler
  node* crawler = root;

  // Scanning the dictionary
  for (char c = fgetc(fd); c != EOF; c = fgetc(fd))
  {
      if (c != '\n')
      {
          // Composing a word
          word[index] = c;
          index++;
      }
      else
      {
          for (int i = 0; i < index; i++)
          {
              cchar = word[i];

              // Determining char's index
              j = (cchar != '\'') ? (cchar - CHARTONUM) : 27;

              /*  Checking if crawler has reached the end and
                  creating a new node if needed */
              if (crawler->paths[j] == NULL)
              {
                  // Initialize a new node to go between the two
                  node* new_node = malloc(sizeof(node));

                  // Check if memory has been allocated successfully
                  if (new_node == NULL)
                  {
                      printf("Out of heap memory\n");
                      return false;
                  }

                  // Moving crawler deeper to another struct
                  crawler->paths[j] == new_node;
              }

              // Moving crawler deeper to another struct
              crawler = crawler->paths[j];
              for (int i = 0; i < 27; i++)
                crawler->paths[i] = NULL;
          }

          // Indicating the end of a word
          crawler->paths[j]->is_word = true;
      }
  }

  fclose(fd);
  return true;
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
