// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 50000;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int index = hash(word);
    node *cursor = table[index];
    for (node *temp = cursor; temp != NULL; temp = temp->next)
    {
        if (strcasecmp(temp->word,word) == 0)
        {
            return true;
        }
    }
    return false;
}


// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    unsigned int hash_value;
    for(int i = 0; i < strlen(word);i++)
    {
        hash_value += tolower(word[i]);
        hash_value =  (hash_value * tolower(word[i])) % N;
    }
    return hash_value;
}

int counter = 0;
// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO

    char words [LENGTH + 1];
    FILE *file = fopen(dictionary, "r");
    if (!file)
    {
         return false;
    }

    while(fscanf(file, "%s", words) != EOF)
    {
        counter ++;

        node *n = malloc(sizeof(node));

        if (n == NULL)
        {
            return 1;
        }

        strcpy(n->word, words);
        n->next = NULL;
        if (table[hash(words)] == NULL)
        {
             table[hash(words)] = n;
        }
        else
        {
            n->next = table[hash(words)];
            table[hash(words)] = n;
        }
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return counter;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for(int i = 0; i < N + 1 ; i ++)
    {
        while (table[i] != NULL)
        {
            node *tmp = table[i]->next;
            free(table[i]);
            table[i] = tmp;
        }
    }
    return true;
}
