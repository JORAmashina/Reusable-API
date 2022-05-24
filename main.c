#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int id;
    void* data;
    size_t size;

    struct Node * next;
}Node;

void add_node (Node** list, int set_id, const void* data, size_t size) //add new data
{
    Node* new_element = (Node*)malloc(sizeof(Node)); 

    memset(new_element, 0, sizeof(new_element));
    new_element -> data = malloc(size);
    memcpy(new_element -> data, data);
    new_element -> id = set_id;
    //new_element -> data = data;
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
                    //*list = (*list) -> next;
                    free(to_delete);
                    break;
                }

        to_delete = to_delete -> next;    
        }      
}

void clear (Node** list)
{
    Node* clear  = *list;

    while (clear -> next != NULL)
    {
        (*list) = (*list) -> next;
        free(clear -> data);
        free(clear);
    }
    free(*list);

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


int main ()
{
    Node* list = NULL;
    int x = 1;
    add_node(&list, 0, &x, sizeof(x));
    x++;
    add_node(&list, 1, &x, sizeof(x));
    x++;
    add_node(&list, 2, &x, sizeof(x));
   
    //clear(&list);
    //delete_to_element_node(&list, 2);
    // Node* to_delete = list;
    // list = list-> next;
    // free(to_delete);

    while (list != NULL)
    {
        printf("id = %d, data = %d\n", list -> id, list -> data);
        list = list -> next;
    }   

    return 0;
}

// clear,write