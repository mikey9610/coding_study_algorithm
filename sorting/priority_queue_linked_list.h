#ifndef PRIORITY_QUEUE_LINKED_LIST
#define PRIORITY_QUEUE_LINKED_LIST

#include "../basic_tools.h"

typedef struct _priority_queue_linked_list_node {
    // data field
    int data_;

    // link field
    struct _priority_queue_linked_list_node* link_;

} PQ_List_Node ;

typedef struct _priority_queue_linked_list {
    PQ_List_Node* header_;
} PQ_List ;

// user interface

PQ_List* PQ_List_new();

int PQ_List_is_empty(PQ_List* pq);
int PQ_List_get_size(PQ_List* pq);
void PQ_List_push(PQ_List* pq, int item);
int PQ_List_pop(PQ_List* pq);

void PQ_List_show(PQ_List* pq);

#endif