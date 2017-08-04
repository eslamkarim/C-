/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "dictionary.h"
#include <ctype.h>
#include <stdio.h>

typedef struct node
{
    bool is_word;
    struct node *children[27];
}node;

node *newNode();
bool recursiveFree(node* trav);
node *root=NULL;
unsigned int dictionary_count = 0;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
   node *ptr=root;
   int index=0;
   
   for(int i = 0; i < strlen(word); i++ )
   {
       if (isalpha(word[i]) || word[i] == '\'')
        {
            if(isalpha(word[i]))
            {
                index = tolower(word[i]);
                index -= 97;
            } else
                index = word[i] - 13;
                if (ptr -> children[index] == NULL)
            {
                return false;
            }
                   //if not goes sets ptr to that child
            else if (ptr -> children[index] != NULL)
            {
                ptr = ptr -> children[index];
            }
        }
    }
if (ptr -> is_word == true)
        return true;
    else
        return false;
   }
   

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    //open the dictionary 
    FILE* fp = fopen(dictionary, "r");
    if (fp == NULL)
    {
        printf("Could not open file");
        return false;
    }
    //init root and set trav to root
    root = newNode();
    node *ptr = root;
    
    //get chars from file checking for EOF
    for (int c = fgetc(fp); c != EOF; c = fgetc(fp))
    {
        if (isalpha(c) || c == '\'')
        {
            //index to 0 from ascii and special case of apostrophe
            if (isalpha(c))
                c -= 97;
            else
                c -= 13;
            //check if node exists
            if (ptr -> children[c] == NULL)
            {
                //create a new node and set child[c] to it and move ptr
                node *n = newNode();
                ptr -> children[c] = n;
                ptr = ptr -> children[c];
            }
            //if node exists move ptr 
            else if(ptr -> children[c] != NULL)
                ptr = ptr -> children[c];
        }
        //if we reach a new line change the value of ptr is_word to true
        else if (c == '\n')
        {
            ptr -> is_word = true;
            ptr = root;
            dictionary_count++;
        }
    }
    fclose(fp);
    return true;
}
/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    
    return dictionary_count;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{

    
    //set trav to root
    node *ptr = root;
    bool end = recursiveFree(ptr);
    if (end == true)
        return true;
    else
        return false;
   
}
bool recursiveFree(node* ptr)
{
    //loops through and if finds pointer to child calls itself on that
    for (int i = 0; i < 27; i++)
    {
        if (ptr -> children[i] != NULL)
        {
            recursiveFree(ptr -> children[i]);
        }
    }
    free(ptr);
    return true;
}
node* newNode()
{
    //creates a new node
    node* n = malloc(1 * sizeof(node));
    n -> is_word = false;
    for (int i = 0; i < 27; i++)
    {
        n -> children[i] = NULL;
    }
    return n;
}