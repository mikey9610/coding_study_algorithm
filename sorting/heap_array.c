#include "heap_array.h"

Heap_Array* Heap_Array_new() {
    Heap_Array* heap = (Heap_Array*)malloc(sizeof(Heap_Array));
    heap->heap_ = (int*)malloc(sizeof(int)*CAPACITY);
    heap->capacity_ = CAPACITY;
    heap->index_ = 0;
    return heap;
}

int Heap_Array_is_empty(Heap_Array* heap) {
    return heap->index_ == 0;
}

int Heap_Array_is_full(Heap_Array* heap) {
    return heap->index_ == heap->capacity_-1;
}

void Heap_Array_swap(Heap_Array* heap, int i1, int i2) {
    int tmp = heap->heap_[i1];
    heap->heap_[i1] = heap->heap_[i2];
    heap->heap_[i2] = tmp;
}

void Heap_Array_up_heap(Heap_Array* heap, int index) {
    if(index == 1)
        return;
    if(heap->heap_[index] < heap->heap_[parent(index)])
        return;
    Heap_Array_swap(heap,index,parent(index));
    Heap_Array_up_heap(heap,parent(index));
}

void Heap_Array_down_heap(Heap_Array* heap, int index) {
    if(heap->index_ < left_child(index))
        return;
    int bigger = left_child(index);
    if(heap->index_ >= right_child(index))
        if(heap->heap_[bigger] < heap->heap_[right_child(index)])
            bigger = right_child(index);
    if(heap->heap_[index] >= heap->heap_[bigger])
        return;
    Heap_Array_swap(heap,index,bigger);
    Heap_Array_down_heap(heap,bigger);
}

void Heap_Array_insert(Heap_Array* heap, int item) {
    if(Heap_Array_is_full(heap))
        Heap_Array_extend(heap);
    heap->index_++;
    heap->heap_[heap->index_] = item;
    Heap_Array_up_heap(heap,heap->index_);
}

int Heap_Array_remove(Heap_Array* heap) {
    if(Heap_Array_is_empty(heap)) {
        printf("error : empty heap");
        return 0;
    }

    int item = heap->heap_[1];
    heap->heap_[1] = heap->heap_[heap->index_];
    heap->index_--;
    Heap_Array_down_heap(heap,1);
    return item;
}

void Heap_Array_show(Heap_Array* heap) {
    int i;
    printf("Heap : ");
    for(i=1;i<=heap->index_;i++)
        printf("%d ",heap->heap_[i]);
    printf("\n");
}

void Heap_Array_extend(Heap_Array* heap) {
    int* new_heap = (int*)malloc(sizeof(int)*heap->capacity_*2);
    for(int i=1;i<=heap->index_;i++)
        new_heap[i] = heap->heap_[i];
    free(heap->heap_);
    heap->heap_ = new_heap;
    heap->capacity_ *= 2;
}