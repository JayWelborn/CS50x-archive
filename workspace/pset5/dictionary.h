/**
 * dictionary.h
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Declares a dictionary's functionality.
 */

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word);

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary);

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void);

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void);

/**
 * declare function used to convert getchar to 0-27
 */
int fix_letter(int c);

/**
 * define Node of Trie data structure for loading the dictionary
 */
typedef struct Node
{
    bool is_word;
    struct Node* letters[27];
} Node;

/**
 * free memory used in trie
 */
void freetrie(Node* node);

#endif // DICTIONARY_H
