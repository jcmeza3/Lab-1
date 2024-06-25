#include "stdio.h"    // Include standard input/output library
#include "stdlib.h"   // Include standard library
#include "malloc.h"   // Include memory allocation library
#include "history.h"  // Include your custom "history" library (assuming it contains necessary data structures)

// Define a function to initialize a history list
List* init_history(){
  List *list = (List*)malloc(sizeof(List));  // Allocate memory for a new list
  list->root = NULL;  // Initialize the list root to be empty
  return list;
}

// Define a function to add a history item to the list
void add_history(List *list, char *str){
  Item *item = (Item*)malloc(sizeof(Item));  // Allocate memory for a new history item
  item->str = str;  // Set the history item's string data
  Item *temp = list->root;  // Create a temporary variable to traverse the list

  if(list->root == NULL){  // If the list is empty
    item->id = 1;  // Set the ID of the first item to 1
    list->root = item;  // Set the root of the list to the new item
  }
  else{
    while(temp->next != NULL){  // Traverse the list to find the last item
      temp = temp->next;
    }
    item->id = temp->id + 1;  // Set the ID of the new item to be one greater than the last item
    temp->next = item;  // Link the new item to the last item
  }
}

// Define a function to get a history item by its ID
char *get_history(List *list, int id){
  char *p = "empty";  // Default string to return if the history item is not found
  Item *temp = list->root;  // Create a temporary variable to traverse the list

  if(list->root == NULL){  // If the list is empty
    return p;  // Return the default "empty" string
  }
  else{
    while(temp->next != NULL && temp->id != id)  // Traverse the list to find the item with the specified ID
      temp = temp->next;
  }
  if(temp->id == id)  // If the item with the specified ID is found
    return temp->str;  // Return the item's string data
  else
    return p;  // Return the default "empty" string
}

// Define a function to print the entire history list
void print_history(List *list){
  int i = 0;
  Item *temp = list->root;  // Create a temporary variable to traverse the list

  while(temp != NULL){  // Loop through the list
    printf("%d. %s\n", temp->id, temp->str);  // Print the ID and string data of each history item
    temp = temp->next;  // Move to the next item in the list
  }
}

// Define a function to free the memory used by the history list
void free_history(List *list){
  Item *temp;
  List *1 = list;  // This should be "List *l = list;" instead of "List *1 = list;"
  
  while(list->root != NULL){  // Loop while there are items in the list
    temp = list->root->next;  // Store the next item in the list
    free(list->root->str);  // Free the string data of the current history item
    free(list->root);  // Free the memory used by the current history item
    list->root = temp;  // Move to the next item in the list
  }
  free(1);  // Free the memory used by the list (should be "free(l);" instead of "free(1);")
}
