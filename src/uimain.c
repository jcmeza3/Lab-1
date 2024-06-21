#include "stdio.h"          // Include the standard input/output library
#include "stdlib.h"         // Include the standard library
#include "tokenizer.h"     // Include your custom "tokenizer" library 
#include "history.h"        // Include your custom "history" library 

int main()
{
  int exit = 1;            // Initialize a variable to control the main loop
  List *list = init_history();  // Create a history list using your "init_history" function

  do{
    // Display a menu for user selection
    printf("Make your selection\n 1. Tokenize 2. Print History 3. Get History 4. Quit (Enter 1, 2, 3, or 4)\n");
    char sel[10];
    printf("> ");
    fgets(sel, 10, stdin);
    char *end;
    int x = strtol(sel, &end, 10);  // Convert the user's input to an integer

    switch(x){
      case 1:{
        char *tokens = (char*)malloc(30 * sizeof(char));  // Allocate memory for input tokens
        printf("> ");
        fgets(tokens, 30, stdin);
        char **t = tokenizer(tokens);  // Tokenize the input and get an array of tokens
        add_history(list, tokens);   // Add the input to the history list
        print_tokens(t);  // Print the tokens
        free_tokens(t);   // Free the memory used by the token array
      } break;

      case 2:{
        print_history(list);  // Print the history list
        break;
      }

      case 3:{
        char id[10];
        printf("Enter ID:\n> ");
        fgets(id, 10, stdin);
        int i = strtol(id, &end, 10);  // Convert the user's input to an integer
        char *h = get_history(list, i);  // Get the history item with the specified ID
        printf("%d. %s\n", i, h);  // Print the history item
        break;
      }

      case 4:{
        exit = 0;  // Set the exit flag to exit the main loop
        break;
      }

      default:
        break;
    }
  } while (exit);  // Continue the loop while the exit flag is not zero

  free_history(list);  // Free the memory used by the history list
  return 0;
}
