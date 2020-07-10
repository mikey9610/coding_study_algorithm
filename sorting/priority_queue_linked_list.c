#include "priority_queue_linked_list.h"

PQ_List* PQ_List_new() {
    PQ_List* pq = (PQ_List*)malloc(sizeof(PQ_List));
    pq->header_ = NULL;
    return pq;
}

int PQ_List_is_empty(PQ_List* pq) {
    return pq->header_ == NULL;
}

int PQ_List_get_size(PQ_List* pq) {
    PQ_List_Node* pVisited = pq->header_;
    int size=0;
    while(pVisited != NULL) {
        pVisited = pVisited->link_;
        size++;
    }
    return size;
}

void PQ_List_push(PQ_List* pq, int item) {
    PQ_List_Node* node = (PQ_List_Node*)malloc(sizeof(PQ_List_Node));
    node->data_ = item;

    //========== selection ==========
    node->link_ = pq->header_;
    pq->header_ = node;
    
    //========== insertion ==========
 /*   if(pq->header_ == NULL) { // pq empty
        node->link_ = NULL;
        pq->header_ = node;
    }
    else {
        PQ_List_Node* pVisited = pq->header_;
        PQ_List_Node* pPrev = NULL;
        while(pVisited != NULL && pVisited->data_ >= item) {
            pPrev = pVisited;
            pVisited = pVisited->link_;
        }
        node->link_ = pVisited;
        if(pPrev != NULL)
            pPrev->link_ = node;  
        else
            pq->header_ = node;
    }*/
}

int PQ_List_pop(PQ_List* pq) {
    PQ_List_Node* node = pq->header_;
    int item;
    
    if(pq->header_ == NULL) { // pq empty
    //========== selection & insertion ==========
        printf("error : empty queue\n");
        return 0;
    }
    else {
    //========== selection ==========
        PQ_List_Node* pVisited = pq->header_;
        PQ_List_Node* pPrev = pq->header_;
        while(pVisited->link_ != NULL) {
            if(pVisited->link_->data_ > node->data_) {
                pPrev = pVisited;
                node = pVisited->link_;
            }
            pVisited = pVisited->link_;
        }
        if(node == pq->header_)
            pq->header_ = node->link_;
        else
            pPrev->link_ = node->link_; 
    
    //========== insertion ==========
       // pq->header_ = pq->header_->link_;
    }
    item = node->data_;
    free(node);
    return item;
}

void PQ_List_show(PQ_List* pq) {
    PQ_List_Node* pVisited = pq->header_;
    
    printf("PQ : ");
    while(pVisited != NULL) {
        printf("%d ",pVisited->data_);
        pVisited = pVisited->link_;
    }
    printf("\n");
}