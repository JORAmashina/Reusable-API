#ifndef LIST_H

#define LIST_H

#include <stddef.h>

typedef struct Node
{
    int id;
    void* data;
    size_t size;

    struct Node * next;
}Node;

enum {
    STK_OK = 0,
    STK_WRONG_ARG=1,
    STK_NOT_ENOUGH_DATA=2,
    STK_MALLOC_FAILED=3
};

void add_node (Node** list, int set_id, const void* data, size_t size); //add new data
void delete_to_element_node (Node** list, int set_id); // delete element

#endif // LIST_H