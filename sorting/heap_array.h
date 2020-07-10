#ifndef HEAP_ARRAY
#define HEAP_ARRAY

#include "../basic_tools.h"

#define CAPACITY    10

#define parent(index) index/2
#define left_child(index) index*2
#define right_child(index) index*2+1

typedef struct _heap_array {
    int* heap_;
    int capacity_;
    int index_;
} Heap_Array ;

// internal
void Heap_Array_swap(Heap_Array* heap, int i1, int i2);
void Heap_Array_up_heap(Heap_Array* heap, int index);
void Heap_Array_down_heap(Heap_Array* heap, int index);

// user interface
Heap_Array* Heap_Array_new();

int Heap_Array_is_empty(Heap_Array* heap);

void Heap_Array_insert(Heap_Array* heap, int item);
int Heap_Array_remove(Heap_Array* heap);

void Heap_Array_show(Heap_Array* heap);

// array ver
int Heap_Array_is_full(Heap_Array* heap);
void Heap_Array_extend(Heap_Array* heap);

#endif