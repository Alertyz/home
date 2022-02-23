// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
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
const unsigned int N = 26;

// Hash table
node *table[N];

int c = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int sum = hash(word);
    
    node *cursor = table[sum];
    
    while (cursor != NULL)
    {
        
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        else
        {
            cursor = cursor->next;
        }
        
    }
    
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // hash table made with the help from >https://research.cs.vt.edu/AVresearch/hashing/strings.php<
    int i = 0, sum = 0;
    while (word[i] != '\0')
    {
        // Makes the lower letters of ASCII match their number in the alphabet 
        if (islower(word[i]) && isalpha(word[i]))
        {
            // Sum each letter into a number
            sum += word[i] - 96;
        }
        
        // Makes the upper letters of ASCII match their number in the alphabet 
        if (isupper(word[i]) && isalpha(word[i]))
        {
            // Sum each letter into a number
            sum += word[i] - 64;
        }
        
        // Next letter
        i++;
        
    }
    
    return sum % N;
    
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    
    // Result from hash
    int number = 0;

    // Open dictionary
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        return false;
    }
    
    // Word
    char w[45];
    
    // Read each word from the dictionary and load it into the linked list
    while (fscanf(dict, "%s", w) != EOF)
    {
        // Allocate space for the new word
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            fclose(dict);
            return false;
        }
        
        // Copy the word
        strcpy(n->word, w);
        n->next = NULL;
        
        // Tells that another word has been added 
        c++;
        
        // Where the word is gonna be added to the hash table
        number = hash(n->word);
        if (table[number] == NULL)
        {
            table[number] = n;
        }
        else
        {
            n->next = table[number];
            table[number] = n;
        }
        
    }
    
    // Close dictionary
    fclose(dict);
    
    return true;
    
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return c;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    int count = 0;
    
    for (int i = 0; i < N; i++)
    {
        
        node *tmp = table[i];
        node *cursor = table[i];
        while (cursor != NULL)
        {
            cursor = cursor->next;
            free(tmp);
            tmp = cursor;
            
        }
        
    }
    
    for (int i = 0; i < N; i++)
    {
        
        if (table[i] == NULL)
        {
            count++;
        }
       
        else
        {
            table[i] = NULL;
            count++;
        }
        
    }
    
    
    if (count == N)
    {
        return true;
    }
    
    
    return false;
    
}
