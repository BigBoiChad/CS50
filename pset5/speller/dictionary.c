// Implements a dictionary's functionality
// https://cs50.harvard.edu/x/2021/psets/5/speller/
// Hash Funtion reference: https://www.educba.com/hashing-function-in-c/ (Quadratic probing)

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
    // the maximam words length is 45
    char word[LENGTH + 1];
    // Hash table is an array of linked list
    struct node *next;
}
node;

// Number of buckets(Blocks) in hash table
// Here we chose the first three letters 26*26*26 (Like the sorting of a pile of card (56 / 4));
// we can chose between 1 ~ 00；
// But we need to balance between the memeory and time
const unsigned int N = 17576;

// Define a Hash table
node *table[N];

// Returns true if word is in dictionary, else false
// Notice it take a string (of character) as an interge
bool check(const char *word)
{
    // TODO
    // create a new node that pointing at the hash table blocks where at least some part of the word (the string) is stored
    // in my case the table has 17576 blocks; if the word we looking for is fool , the pointer will point at the foo blocks
    // if the word is are (which is at are blocks) the pointer will point at this blocks)
    // hash(word) return a index; that index is in the blocks where the some part of word (the string) is found
    // If the cursor = NULL; means the word (part or all) does not belong in any of the blocks in table
    // ie (aaac) the first three aaa dont even have a block ('aaa' is not a part of word)
    // therefore the table[hash(aaa)] == NULL
    // check function return false
    node *cursor = table[hash(word)];
    while (cursor != NULL)
    {
        // now we compare two words with one another
        // the word we take as an input and the word in the table which contains the dictionary.
        // cursor-> word if exist means the word exist
        // for example the word 'fool' first in the foo blocks
        // the compare is not the same
        // point to the next block (fool) that successed
        // we found the word
        // if the word is 'aaa' we follow the pointer(cursor) and find there is not word --- cursor == NULL
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        // point to the next block (fool) that successed
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
// unsigned int means the int is not a negative integer
unsigned int hash(const char *word)
{
    // TODO
    // we need to set the first value to be 0
    // because the hash table blocks literally starts at 0
    unsigned int hash_value = 0;

    for (int i = 0; i < strlen(word); i++)
    {
        // make evey word we check to be lower case
        hash_value += tolower(word[i]);
        // this is the hash funciton
        // which takes an input word and gives a integer (0xFF...)
        // this is called the quadratic probing
        // https://www.educba.com/hashing-function-in-c/
        hash_value = (hash_value + tolower(word[i]) * tolower(word[i])) % N;
    }
    return hash_value;
}

int counter = 0;
// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // we make a string that will store each word in the dictionary
    // the longers word has 45 characters
    char words [LENGTH + 1];
    // we create a file that will be the same as dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }
    // fscanf will scan the file and then put the "s"- string type data into a list call word
    // Notice once we define the "s"-string
    // the fscanf will automatically take every word (since a strng is a list of character and end with '\n')
    // thats why the dictionary contains only one word every line
    // when reach to the null the bottom of the file, Fscanf will return the EOF
    while (fscanf(file, "%s", words) != EOF)
    {
        // every time to copy a word we need to take intp counters
        counter ++;

        // we create a node just for store each incoming word
        node *n = malloc(sizeof(node));

        if (n == NULL)
        {
            return 1;
        }

        // we copy each word to the n linked list
        strcpy(n->word, words);
        // we set the pointer to NULL for now
        n->next = NULL;
        // now we need  to insert this word intp the table
        // first we need to make sure whether the table has a block where the words belongs
        // that is to check whether the table[hash(word)] exist (!= NULL)
        // if it doest not contain a block that covers this word
        // we simply make the table[hash[word]] point at the n node.
        if (table[hash(words)] == NULL)
        {

            table[hash(words)] = n;
        }
        else
        {
            // Otherwise we need to insert the word in a existing block
            // meaning we need to change the head to pointer at the n node without
            // lost the rest of blocks
            // first we make the n pointing at the head of the block
            // that way we dont lost the rest of the blocks
            n->next = table[hash(words)];
            // we change the head pointer to pointing at the n node instead.
            table[hash(words)] = n;
        }
    }
    // Notice to always close the file
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return counter;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // Notice we need to clean every N blocks per vetical line
    // But not lost the rest of blocks
    // For each vertical line (parent line)
    // we clean N times
    for (int i = 0; i < N ; i ++)
    {
        // If the table[] (one vertical line is not wrap out)
        // meaing there still blocks remain
        while (table[i] != NULL)
        {
            // we need to create a tmp node to point at the next vetical line (so we dont lost track)
            node *tmp = table[i]->next;
            // we free this current line
            free(table[i]);
            // the update the hash table
            table[i] = tmp;
        }
    }
    return true;
}
