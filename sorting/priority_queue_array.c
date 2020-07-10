#include "priority_queue_array.h"

int PQ_Array_is_full(PQ_Array* pq) {
    return pq->size_ == pq->index_;
}

void PQ_Array_extend(PQ_Array* pq) {
    int* new_queue = (int*)malloc(sizeof(int)*(pq->size_*2));
    int i;
    
    for(i=0;i<pq->size_;i++)
        new_queue[i] = pq->queue_[i];

    free(pq->queue_);
    pq->queue_ = new_queue;
    pq->size_ = pq->size_*2;
}

PQ_Array* PQ_Array_new() {
    PQ_Array* pq = (PQ_Array*)malloc(sizeof(PQ_Array));
    pq->queue_ = (int*)malloc(sizeof(int)*CAPACITY);
    pq->size_ = CAPACITY;
    pq->index_ = 0;
    return pq;
}

int PQ_Array_is_empty(PQ_Array* pq) {
    return pq->index_ == 0;
}

int PQ_Array_get_size(PQ_Array* pq) {
    return pq->index_;
}
void PQ_Array_push(PQ_Array* pq, int item) {
    // selection & insertion
    if(PQ_Array_is_full(pq))
        PQ_Array_extend(pq);

    // selection
    pq->queue_[pq->index_] = item;
    
    // insertion
    int pos = 0, i;
    while(pos<pq->index_ && item > pq->queue_[pos])
        pos++;

    for(i=pq->index_;i>pos;i--)
        pq->queue_[i] = pq->queue_[i-1];
    
    pq->queue_[pos] = item;

    // selection & insertion
    pq->index_++; 
}

int PQ_Array_pop(PQ_Array* pq) {
    // queue empty
    if(PQ_Array_is_empty(pq)) {
        printf("error : empty queue\n");
        return 0;
    }

    int item;
    // selection
    int i, index=0;
    for(i=1;i<pq->index_;i++) {
        if(pq->queue_[i] > pq->queue_[index])
            index = i;
    }
    item = pq->queue_[index];
    for(i=index;i<pq->index_-1;i++) {
        pq->queue_[i] = pq->queue_[i+1];
    }

    // insertion
    item = pq->queue_[pq->index_-1];

    // selection & insertion
    pq->index_--;
    return item;
}

void PQ_Array_show(PQ_Array* pq) {
    int i;
    printf("PQ : ");
    for(i=0;i<pq->index_;i++)
        printf("%d ",pq->queue_[i]);
    printf("\n");
}