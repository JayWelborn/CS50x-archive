/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include "dictionary.h"

// declare root of the trie as global variable
Node root;

// declare global variable num_words
unsigned int num_words = 0;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // checks length of word for loop, and sets root as current Node
    int len = strlen(word);
    Node* cur_node = &root;
    
    /**
     * loop iterates through each character in word to see if the nodes
     * exist in the trie. If they do, returns true
     */
    for (int i = 0; i <= len; i++)
    {
        int c = fix_letter(word[i]);
        
        if (i == len && cur_node->is_word == true)
        {
            return true;
        }
        
        // returns false if next letter isn't a Node
        else if (i != len && cur_node->letters[c] == NULL)
        {
            return false;
        }
        
        else
        {
            cur_node = cur_node->letters[c];
        }
    }
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // open dictionary for reading
    FILE* dict = fopen(dictionary, "r");
    
    if (dict == NULL)
    {
        perror("\nfopen error.\n");
        return false;
    }

    // declare pointer "current Node" and set it equal to the root
    Node* cur_node = &root;

    // loop reads dictionary into Trie
    for (int c = fgetc(dict); c != EOF; c = fgetc(dict))
    {
        // puts letters into trie
        if (c != 10)
        {
            c = fix_letter(c);
            
             // callocs space for new node if letter isn't in trie
            if (cur_node->letters[c] == NULL)
            {
                cur_node->letters[c] = calloc(1, sizeof(Node));
                cur_node = cur_node->letters[c];
            }
            
             // if letter already exists, sets next Node as current
            else
            {
                cur_node = cur_node->letters[c];
            }
        }
        
         // sets is_word to true and moves back to root when reaching a newline
        else if (c == 10)
        {
            cur_node->is_word = true;
            cur_node = &root;
            num_words += 1;
        }
    }
    // close dictionary when finished
    fclose(dict);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return num_words;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    freetrie(&root);
    return true;
}

/**
 * Takes ascii value from fgetc, and converts it so the letters
 * correspond with indeces in the trie pointer array.
 */
int fix_letter(int c)
{
    if (97 <= c && c <= 122)
    {
        return c - 97;
    }
    else if (65 <= c && c <= 90)
    {
        return c - 65;
    }
    else if (c == 39)
    {
        return 26;
    }
    else
    {
        return c;
    }
}

// recursively free all nodes in trie
void freetrie(Node* node)
{
    for (int i = 0; i < 27; i++)
    {
        if (node->letters[i] != NULL)
        {
            freetrie(node->letters[i]);
        }
    }
    if (node != &root)
    {
        free(node);
    }
}