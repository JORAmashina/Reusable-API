#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int id;
    void* data;
    size_t size;

    struct Node * next;
}Node;

void add_node (Node** list, int set_id, const void* set_data) //add new data
{
    Node* new_element = (Node*)malloc(sizeof(Node)); 

    new_element -> id = set_id;
    new_element -> data = set_data;

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

    add_node(&list, 0, &"1");
    // add_node(&list, 1, "2");
    // add_node(&list, 2, "3");
   
    clear(&list);
    //delete_to_element_node(&list, 2);
    // Node* to_delete = list;
    // list = list-> next;
    // free(to_delete);

    while (list != NULL)
    {
        printf("id = %d, data = %s\n", list -> id, list ->data);
        list = list -> next;
    }   

    return 0;
}

// clear,write