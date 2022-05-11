#include <stdio.h>
#include <stdlib.h>
#include "history.h"
 
/* Initialize the linked list to keep the history. */
List* init_history() {
  List *history = (List*)malloc(sizeof(List*));
  history -> root = NULL;
  return history;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str)
{

  Item *new_node = (Item*)malloc(sizeof(Item));
  new_node -> str = str;
  new_node -> next = NULL;
  
  Item *temp_list = list -> root;

  if(!temp_list) {   // if linked list not populated make new node root
    new_node -> id = 0;
    list -> root = new_node;
    return;
  }
  
  int i = 0;
  while (temp_list -> next != NULL) {   // while l-list has next; finding tail
    temp_list = temp_list -> next;
    i++;
  }
  new_node -> id = i;   // new-node assgined tail id + 1
  temp_list -> next = new_node;   // new-node assigned as next of tail
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id)
{
  if(!(list -> root)) {
    printf("There is no stored history.(\n)");
    return '\0';
  }

  Item *temp = list -> root;
  for (int i = 0; i < id; i++){
    temp = temp -> next;   // traversing l-list till id we're looking for
  }

  return temp -> str;   // ret str @ loc id
}

/*Print the entire contents of the list. */
void print_history(List *list)
{
  if(!(list -> root)) {
    printf("There is no stored history.(\n)");
    return;
  }
  
  Item *temp = list -> root;
  printf("Tokenized history:\n");
  while (temp) {
    printf("[%d] - %s\n", temp -> id, temp -> str);
    temp = temp -> next;   // traversing l-list
  }
}
/*Free the history list and the strings it references. */
void free_history(List *list) {
  Item *temp = list -> root;

  while(list -> root) {
    temp = list -> root;
    list -> root = list -> root -> next;
    free(temp);
  }
  free(list);
}


