#ifndef PRIORITY_QUEUE_ARRAY
#define PRIORITY_QUEUE_ARRAY

#include "../basic_tools.h"

#define CAPACITY    5

typedef struct _priority_queue_array {
    int size_;
    int index_;
    int* queue_;
} PQ_Array ;

// internal functions

int PQ_Array_is_full(PQ_Array* pq);
void PQ_Array_extend(PQ_Array* pq);

// user interface

PQ_Array* PQ_Array_new();

int PQ_Array_is_empty(PQ_Array* pq);
void PQ_Array_push(PQ_Array* pq, int item);
int PQ_Array_pop(PQ_Array* pq);
void PQ_Array_show(PQ_Array* pq);

int PQ_Array_get_size(PQ_Array* pq);

#endif