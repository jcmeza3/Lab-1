#include "stdio.h"         // Include the standard input/output library
#include "malloc.h"        // Include the memory allocation library
#include "tokenizer.h"     // Include your custom "tokenizer" library (assuming it contains necessary data structures)

// Function to check if a character is a space or tab
int space_char(char c)
{
  if (c == ' ' || c == '\t') return 1;  // If the character is a space or tab, return 1 (true)
  else return 0;  // Otherwise, return 0 (false)
}

// Function to check if a character is not a space or tab
int non_space_char(char c)
{
  if (!space_char(c)) return 1;  // If the character is not a space or tab, return 1 (true)
  else return 0;  // Otherwise, return 0 (false)
}

// Function to find the start of the next token in a string
char *token_start(char *str)
{
  while (*str != '\0'){
    if (non_space_char(*str)) return str;  // If a non-space character is found, return its position
    str++;
  }
  return str;  // If no non-space character is found, return the end of the string
}

// Function to find the end of the current token in a string
char *token_terminator(char *word)
{
  while (*word != '\0'){
    if (space_char(*word)) return word;  // If a space or tab character is found, return its position
    word++;
  }
  return word;  // If no space or tab character is found, return the end of the string
}

// Function to count the number of tokens in a string
int count_tokens(char *str)
{
  int c = 0;
  if (*str == '\n') return c;  // If the string starts with a newline character, return 0 tokens
  while (*str != '\0'){
    str = token_start(str);  // Find the start of the next token
    if (*str) c++;  // If there is a character at the token start, increment the token count
    str = token_terminator(str);  // Find the end of the current token
  }
  return c;  // Return the total token count
}

// Function to copy a string with a specified length
char *copy_str(char *inStr, short len)
{
  char *scopy = malloc((len + 1) * sizeof(char)), c;
  int sindex = 0;
  do {
    c = *(scopy + sindex) = *(inStr + sindex);
    sindex++;
  } while (sindex < len);
  *(scopy + sindex) = '\0';  // Add a null terminator to the copied string
  return scopy;
}

// Function to tokenize a string and return an array of token strings
char **tokenizer(char *str)
{
  int i = count_tokens(str);
  char **t = malloc((i + 1) * sizeof(char*));  // Allocate memory for the token array
  int tindex = 0;
  while (*str != '\0'){
    str = token_start(str);  // Find the start of the next token
    char *sc = str;
    sc = token_terminator(sc);  // Find the end of the current token
    int len = sc - str;  // Calculate the length of the token
    *(t + tindex) = &(*copy_str(" ", 1));  // Assign a copied token to the array (This seems incorrect and should be modified)
    return t;  // Return the token array
  }
}

// Function to print the tokens in an array of token strings
void print_tokens(char **tokens)
{
  int i = 0;
  while (**tokens != ' '){  // This condition should be modified
    printf("t[%d] = %s\n", i, *tokens);  // Print the index and the token
    *tokens++;
    i++;
  }
}

// Function to free the memory used by an array of token strings
void free_tokens(char **tokens)
{
  char **t;
  t = tokens;
  while (**t != ' '){  // This condition should be modified
    free(*t);  // Free the memory used by a token
    *t++;
  }
  free(*t);  // Free the memory used by a placeholder (This should be improved)
  free(tokens);  // Free the memory used by the token array
}
