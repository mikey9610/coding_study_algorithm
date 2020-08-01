#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

#include "../basic_tools.h"

#define BST_NO_SUCH_ITEM	-1

typedef struct _binary_search_tree_node Bst_node;

Bst_node* bst_create_node(Bst_node*);

int bst_is_external(Bst_node*);
int bst_is_internal(Bst_node*);
void bst_expand_external(Bst_node*);
void bst_reduce_external(Bst_node*);
Bst_node* bst_in_order_succ(Bst_node*);

struct _binary_search_tree_node {

	int data_;
	
	struct _binary_search_tree_node* parent_;
	
	struct _binary_search_tree_node* left_child_;
	struct _binary_search_tree_node* right_child_;

	int(*is_external)(Bst_node*);
	int(*is_internal)(Bst_node*);
	void(*expand_external)(Bst_node*);
	void(*reduce_external)(Bst_node*);
	Bst_node*(*in_order_succ)(Bst_node*);
};


typedef struct _binary_search_tree Bst;

Bst* bst_create_tree();
void bst_test_show(Bst*);

Bst_node* bst_find_r(Bst_node*,int);

int bst_is_empty(Bst*);
int bst_find(Bst*,int);
void bst_insert(Bst*,int);
void bst_remove(Bst*,int);

struct _binary_search_tree {
	Bst_node* root_;

	int(*is_empty)(Bst*);
	int(*find)(Bst*,int);
	void(*insert)(Bst*,int);
	void(*remove)(Bst*,int);

};

#endif