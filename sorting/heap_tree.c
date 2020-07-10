#include "heap_tree.h"

void Heap_Tree_swap(Heap_Tree_Node* node1, Heap_Tree_Node* node2) {
    int tmp = node1->data_;
    node1->data_ = node2->data_;
    node2->data_ = tmp;
}

void Heap_Tree_up_heap(Heap_Tree* heap, Heap_Tree_Node* node) {
    if(node == heap->root_)
        return;    
    if(node->data_ <= node->parent_->data_)
        return;    
    Heap_Tree_swap(node,node->parent_);
    Heap_Tree_up_heap(heap,node->parent_);
}

void Heap_Tree_down_heap(Heap_Tree* heap, Heap_Tree_Node* node) {
    if(Heap_Tree_is_external(node->left_child_))    // if left is external, surely right is external either
        return;
    Heap_Tree_Node* bigger = node->left_child_;
    if(Heap_Tree_is_internal(node->right_child_)) {
        if(bigger->data_ < node->right_child_->data_)
            bigger = node->right_child_;
    }
    if(node->data_ >= bigger->data_)
        return;
    Heap_Tree_swap(node,bigger);
    Heap_Tree_down_heap(heap,bigger);
}

Heap_Tree* Heap_Tree_new() {
    Heap_Tree* heap = (Heap_Tree*)malloc(sizeof(Heap_Tree));
    heap->root_ = (Heap_Tree_Node*)malloc(sizeof(Heap_Tree_Node));
    heap->last_ = NULL;
    return heap;
}

int Heap_Tree_is_empty(Heap_Tree* heap) {
    return Heap_Tree_is_external(heap->root_);
}

void Heap_Tree_insert(Heap_Tree* heap, int item) {
    Heap_Tree_advance_last(heap);
    Heap_Tree_expand_external(heap->last_);
    heap->last_->data_ = item;
    Heap_Tree_up_heap(heap,heap->last_);
}

int Heap_Tree_remove(Heap_Tree* heap) {
    int item = heap->root_->data_;
    Heap_Tree_swap(heap->root_,heap->last_);
    Heap_Tree_reduce_external(heap->last_);
    Heap_Tree_retreat_last(heap);
    Heap_Tree_down_heap(heap,heap->root_);
    return item;
}

void Heap_Tree_show(Heap_Tree* heap) {
    printf("Heap : ");
    Heap_Tree_in_order_traversal(heap->root_); 
    printf("\n"); 
}

// tree ver
int Heap_Tree_is_left_child(Heap_Tree_Node* node) {
    return node->parent_ != NULL && node == node->parent_->left_child_;
}

int Heap_Tree_is_right_child(Heap_Tree_Node* node) {
    return node->parent_ != NULL && node == node->parent_->right_child_;
}

int Heap_Tree_is_external(Heap_Tree_Node* node) {
    return node->left_child_ == NULL;
}

int Heap_Tree_is_internal(Heap_Tree_Node* node) {
    return node->left_child_ != NULL;
}

void Heap_Tree_advance_last(Heap_Tree* heap) {
    if(heap->last_ == NULL)
        heap->last_ = heap->root_;
    else {
        while(Heap_Tree_is_right_child(heap->last_))
            heap->last_ = heap->last_->parent_;

        if(Heap_Tree_is_left_child(heap->last_))
            heap->last_ = heap->last_->parent_->right_child_;
        
        while(Heap_Tree_is_internal(heap->last_))
            heap->last_ = heap->last_->left_child_;
    }
}

void Heap_Tree_retreat_last(Heap_Tree* heap) {
    if(heap->last_ == heap->root_)
        heap->last_ = NULL;
    else {
        while(Heap_Tree_is_left_child(heap->last_))
            heap->last_ = heap->last_->parent_;

        if(Heap_Tree_is_right_child(heap->last_))
            heap->last_ = heap->last_->parent_->left_child_;
        
        while(Heap_Tree_is_internal(heap->last_->right_child_))
            heap->last_ = heap->last_->right_child_;
    }
}

void Heap_Tree_expand_external(Heap_Tree_Node* node) {
    node->left_child_ = (Heap_Tree_Node*)malloc(sizeof(Heap_Tree_Node));
    node->left_child_->left_child_ = NULL;
    node->left_child_->right_child_ = NULL;
    node->left_child_->parent_ = node;
    node->right_child_ = (Heap_Tree_Node*)malloc(sizeof(Heap_Tree_Node));
    node->right_child_->left_child_ = NULL;
    node->right_child_->right_child_ = NULL;
    node->right_child_->parent_ = node;
}

void Heap_Tree_reduce_external(Heap_Tree_Node* node) {
    free(node->left_child_);
    free(node->right_child_);
    node->left_child_ = NULL;
    node->right_child_ = NULL;
}

void Heap_Tree_in_order_traversal(Heap_Tree_Node* node) {
    if(Heap_Tree_is_internal(node->left_child_))   
        Heap_Tree_in_order_traversal(node->left_child_);
    printf("%d ",node->data_);
    if(Heap_Tree_is_internal(node->right_child_))
        Heap_Tree_in_order_traversal(node->right_child_);
}