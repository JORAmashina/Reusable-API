#include<stddef.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include "list.h"


void clear (Node** list)
{
    Node* clear  = *list;

    // free((*list) -> data);
    // free((*list) -> next);

    // (*list) = (*list) -> next;
    // free(clear ->  data);
    // free(clear);
    while (clear -> next == NULL)
        {
            (*list) = (*list) -> next;
            free(clear -> data);
            free(clear);
        }
    

}


int main ()
{
    Node* list = NULL;

    char x []= "hello world";
    add_node(&list, 0, x, sizeof(x));
    //x++;
    add_node(&list, 1, x, sizeof(x));
    //x++;
    add_node(&list, 2, x, sizeof(x));

    clear(&list);
    
    while (list != NULL)
    {
        printf("id = %d, data = %s\n", list -> id, list -> data);
        list = list -> next;
    }   

    int y = 123;
    add_node(&list, 3, &y, sizeof(y));
    y++;
    add_node(&list, 4, &y, sizeof(y));
    y++;
    add_node(&list, 5, &y, sizeof(y));
   
    clear(&list);
    //delete_to_element_node(&list, 2);
    // Node* to_delete = list;
    // list = list-> next;
    // free(to_delete);

    while (list != NULL)
    {
        printf("id = %d, data = %d\n", list -> id, *(int*)list -> data);
        list = list -> next;
    }   

    //getch();
    return 0;
}

// clear,write