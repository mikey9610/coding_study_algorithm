#ifndef HEAP_TREE
#define HEAP_TREE

#include "../basic_tools.h"

typedef struct _heap_tree_node {
    // data field
    int data_;

    // link field
    struct _heap_tree_node* parent_;
    struct _heap_tree_node* left_child_;
    struct _heap_tree_node* right_child_;

} Heap_Tree_Node ;

typedef struct _heap_tree {
    Heap_Tree_Node* root_;
    Heap_Tree_Node* last_;
} Heap_Tree ;

// internal
void Heap_Tree_swap(Heap_Tree_Node* node1, Heap_Tree_Node* node2);
void Heap_Tree_up_heap(Heap_Tree* heap, Heap_Tree_Node* node);
void Heap_Tree_down_heap(Heap_Tree* heap, Heap_Tree_Node* node);

// user interface
Heap_Tree* Heap_Tree_new();

int Heap_Tree_is_empty(Heap_Tree* heap);

void Heap_Tree_insert(Heap_Tree* heap, int item);
int Heap_Tree_remove(Heap_Tree* heap);

void Heap_Tree_show(Heap_Tree* heap);

// tree ver
int Heap_Tree_is_left_child(Heap_Tree_Node* node);
int Heap_Tree_is_right_child(Heap_Tree_Node* node);

int Heap_Tree_is_external(Heap_Tree_Node* node);
int Heap_Tree_is_internal(Heap_Tree_Node* node);

void Heap_Tree_advance_last(Heap_Tree* heap);
void Heap_Tree_retreat_last(Heap_Tree* heap);

void Heap_Tree_expand_external(Heap_Tree_Node* node);
void Heap_Tree_reduce_external(Heap_Tree_Node* node);

void Heap_Tree_in_order_traversal(Heap_Tree_Node* node);

#endif