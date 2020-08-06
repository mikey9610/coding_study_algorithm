#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

#include <stdio.h>
#include <stdlib.h>

#define BST_NO_SUCH_ITEM	-1

typedef struct _bst_node {
	int data_;
	// data field

	struct _bst_node* parent_;
	struct _bst_node* left_child_;
	struct _bst_node* right_child_;
	// link field
} Bst_node ;

typedef struct _bst {
	Bst_node* root_;
} Bst ;

Bst_node* bst_create_node(Bst_node*);

int bst_is_external(Bst_node*);	// 외부 노드 인지 반환
int bst_is_internal(Bst_node*);	// 내부 노드 인지 반환
void bst_expand_external(Bst_node*);	// node external -> internal : left,right external node
void bst_reduce_external(Bst_node*,Bst*);

Bst_node* bst_in_order_succ(Bst_node*);

Bst* bst_create_tree();

int bst_is_empty(Bst*);
Bst_node* bst_find_r(Bst_node*,int);
int bst_find(Bst*,int);
void bst_insert(Bst*,int);
void bst_remove(Bst*,int);

void bst_test_show_r(Bst_node*);
void bst_test_show(Bst*);

#endif