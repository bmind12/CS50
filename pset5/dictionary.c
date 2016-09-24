/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "dictionary.h"

int CHARTONUM = 97;
int MAXPATHS = 27;

typedef struct node
{
  bool is_word;
  struct node* paths[27];
}
node;

node* root;

char* lower(char* word);
void free_trie(node* crawler);

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


    // Openning the dictionary
    FILE* fd = fopen(dictionary, "r");

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
    for (int i = 0; i < MAXPATHS; i++)
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
                j = (cchar != '\'') ? (cchar - CHARTONUM) : MAXPATHS;

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
                    crawler->paths[j] = new_node;
                }

                // Moving crawler deeper to another struct
                crawler = crawler->paths[j];
                for (int i = 0; i < MAXPATHS; i++)
                  crawler->paths[i] = NULL;
            }

            // Indicating the end of a word
            crawler->is_word = true;
            index = 0;
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
    return 0;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // Passes a pointer to the first struct to free_trie function
    free_trie(root);
    return true;
}

/**
 * Lowercases each word's letter
 */
char* lower(char* word)
{
    // Defining lenght of a word
    int len = strlen(word);

    // Looping through the word makeing capitals to be lowercase
    for (int i = 0; i < len; i++)
    {
    if (word[i] > 'A' && word[i] < 'Z')
      word[i] += 32;
    }

    return word;
}

/**
 *  Recurively frees the memory of a trie
 */
void free_trie(node* crawler)
{
    node* child;

    // Looping thriygh each pointer to a struct and freeing once reached the end
    for (int i = 0; i < MAXPATHS + 1; i++)
    {
        if (crawler->paths[i] != NULL)
        {
            child = crawler->paths[i];
            free_trie(child);
        }
        else
        {
            free(crawler);
            return;
        }
    }
}
