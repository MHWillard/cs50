// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include "dictionary.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26*26; //buckets for A-Z: 26*26 to get a big bucket size to avoid seg faults

// Hash table
node *table[N];

//variables for reading dictionary words
int added_words = 0;
char buffer[45];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int i = hash(word);
    if (table[i] != NULL) {
        //set head of the list to equal table[i]
        node *current = table[i];
        while (current != NULL) {
            //compare and return true if good; otherwise, set head to the next node to continue iterating until NULL
            if (strcmp(current->word, word)) return true;
                current = current->next;
            }
        return false;
    }
    return false;
}

// Hashes word to a number
//Dan Bernstein's djb2 hashing algorithm:

unsigned int hash(const char *word)
{
    unsigned int hash = 5381;
    int c;

    //TODO: reduce word to lowercase FIRST, THEN hash it to be case-insensitive)

    while ((c = *word++)) {
        hash = ((hash << 5) + hash) + c;
    }
    //by doing modulo we can reduce the number to an expected range: do it by N
        return hash % N;
}


// Loads dictionary into memory, returning true if successful, else false
//load into hash table: find how to implement this in C (hashtable struct, node struct, use nodes -> build lists > assign them to indexes of hashtable struct?)
//oh look use the node and hash table above: find each word in dict and load in, use small one to test
bool load(const char *dictionary)
{
    // TODO
    FILE *infile = fopen(dictionary, "r");
    if (infile != NULL) {
        while (fscanf(infile, "%s", buffer) != EOF) {
            node *n = malloc(sizeof(node));
            strcpy(n->word, buffer);
            //keep track of number of added words for size
            added_words++;
            int i = hash(buffer);

            if (table[i] == NULL) {
                n->next = NULL;
                table[i] = n;
            } else {
                //add temp value to catch first item of list: adds this node to the start of the list
                n->next = table[i];
                table[i] = n;
            }
        }
        return true;
    }
    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if (added_words >= 0) {
        return added_words;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    //iterate through hash table, freeing each node
    for (int i = 0; i <= N; i++) {
        //set up current head of node to work with
        node *current = table[i];

        //we found something
        if (table[i] != NULL) {

            //point current to next, free temp, repeat
            while (current != NULL) {
                //set up temp first
                node *temp = current;
                current = current->next;
                free(temp);
            }
        }
        if (i == N-1 && current == NULL) {
            return true;
        }
    }
    return false;
}
