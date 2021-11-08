/*
Implement a program that spell-checks a file, a la the below, using a hash table.

$ ./speller texts/lalaland.txt
MISSPELLED WORDS

[...]
AHHHHHHHHHHHHHHHHHHHHHHHHHHHT
[...]
Shangri
[...]
fianc
[...]
Sebastian's
[...]

WORDS MISSPELLED:
WORDS IN DICTIONARY:
WORDS IN TEXT:
TIME IN load:
TIME IN check:
TIME IN size:
TIME IN unload:
TIME IN TOTAL:
*/

// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include "dictionary.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <strings.h>

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

//variables for reading and checking dictionary words
int added_words = 0;
char buffer[45];
char lower[45];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    //use copy of word and lowercase it to compare against dict
    strcpy(lower, word);
    for (int x = 0; x<=strlen(lower); x++) {
        if (lower[x] >= 65 && lower[x] <= 90) {
            lower[x] = lower[x]+32;
        }
    }

    int i = hash(lower);

    //set head of the list to equal table[i]
    node *current = table[i];
    while (current != NULL) {
        //compare and return true if good; otherwise, set head to the next node to continue iterating until NULL
        if (strcasecmp(current->word, lower) == 0) {
            return true;
        }
            //return true FIRST, then point to the next node
            current = current->next;
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
            int i = hash(buffer);

            if (table[i] == NULL) {
                n->next = NULL;
                table[i] = n;
                //keep track of number of added words for size
                //read table[i]->word: print what's there, and only if something is there, add++ to words
                //printf("word: %s\n", table[i]->word);
                added_words++;
            } else {
                //add temp value to catch first item of list: adds this node to the start of the list
                n->next = table[i];
                table[i] = n;
                //keep track of number of added words for size
                //printf("word: %s\n", table[i]->word);
                added_words++;
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