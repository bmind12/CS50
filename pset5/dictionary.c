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
int WORDSNUM = 0;

typedef struct node
{
  bool is_word;
  struct node* paths[27];
}
node;

node* root;

char lower(char c);
void free_trie(node* crawler);

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // Converting to lowercase
    int len = strlen(word);
    char lchar;

    // Defining and linking a crawler
    node* crawler = root;

    for (int i = 0, j = 0; i < len; i++)
    {
        lchar = lower(word[i]);

        // Determining char's index
        j = (lchar != '\'') ? (lchar - CHARTONUM) : MAXPATHS - 1;

        // Continiously digging into structure if door is closed -> return false
        if (crawler->paths[j] == NULL)
        {
            return false;
        }
        else
        {
            // Moving crawler deeper to another struct
            crawler = crawler->paths[j];
        }
    }

    return (crawler->is_word == true) ? true : false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
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
    {
        root->paths[i] = NULL;
    }
    root->is_word = false;

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
                // Determining char's index
                j = (word[i] != '\'') ? (word[i] - CHARTONUM) : MAXPATHS - 1;

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

                    // Moving crawler deeper to a newly created struct
                    crawler->paths[j] = new_node;
                    crawler = crawler->paths[j];
                    for (int i = 0; i < MAXPATHS; i++)
                    {
                        crawler->paths[i] = NULL;
                    }
                    crawler->is_word = false;
                }
                else
                {
                    // Moving crawler deeper to another struct
                    crawler = crawler->paths[j];
                }

            }

            /*  Indicating the end of a word, counting words and
                coming back to root */
            crawler->is_word = true;
            WORDSNUM++;
            crawler = root;
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
    return WORDSNUM;
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
char lower(char c)
{
    return (c >= 'A' && c <= 'Z') ? c += 32 : c;
}

/**
 *  Recurively frees the memory of a trie
 */
void free_trie(node* crawler)
{
    // Looping thriygh each pointer to a struct and freeing once reached the end
    for (int i = 0; i < MAXPATHS; i++)
    {
        if (crawler->paths[i] != NULL)
            free_trie(crawler->paths[i]);
    }

    free(crawler);
    return;

}
