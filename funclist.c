#include <stdio.h>
#include "list.h"
#include<stdlib.h>
#include<stddef.h>
#include <string.h>


void add_node (Node** list, int set_id, const void* data, size_t size) //add new data
{
    Node* new_element = (Node*)malloc(sizeof(Node)); 

    memset(new_element, 0, sizeof(new_element));
    new_element -> data = malloc(size);
    memcpy(new_element -> data, data, size);
    
    new_element -> id = set_id;
    new_element -> size = size;

    new_element -> next = *list;
    *list = new_element;
}


void delete_to_element_node (Node** list, int set_id) // delete element
{
    Node* to_delete = *list;

    while (to_delete -> next != NULL)
        {   
            if ((*list) -> id == set_id)
                {
                    *list = (*list) -> next;
                    free(to_delete);
                    break;
                }
            else if (to_delete -> id == set_id)
                {       
                    (*list) -> next = to_delete -> next;
                    free(to_delete);
                    break;
                }

        to_delete = to_delete -> next;    
        }      
}



// size_t stack_size(const Node* list)
// { // TODO: count size here
//     Node* curr;
//     if (list != NULL)
//         memcpy(&curr, &list, sizeof(Node*));
//     else
//         return 0;
//     size_t i = 1;
//     while (curr = curr->next)
//         i++;
//     return i;
// }


// void reset_node_to_id (Node** list,int set_id, char* set_data)
// {
//     while (list != NULL) 
// }

// void node_to_end (Node** list, int set_id, char* set_data)
// {
//     Node* new_element = (Node*)malloc(sizeof(Node));

//     new_element -> id = set_id;
//     new_element -> data = set_data;

//     Node *tmp = *list;
//     while (tmp -> next != NULL)
//     {
//         tmp = tmp -> next;
//     }

//     tmp -> next = new_element;
//     new_element -> next = NULL;        
// }