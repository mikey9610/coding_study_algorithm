#include "binary_search_tree.h"

Bst_node* bst_create_node(Bst_node* parent) {
	Bst_node* node = (Bst_node*)malloc(sizeof(Bst_node));
	node->left_child_ = NULL;
	node->right_child_ = NULL;
	node->parent_ = parent;
	return node;
}

int bst_is_external(Bst_node* node) {
	return node->left_child_==NULL && node->right_child_==NULL;
}

int bst_is_internal(Bst_node* node) {
	return node->left_child_!=NULL || node->right_child_!=NULL;
}

void bst_expand_external(Bst_node* node) {
	node->left_child_ = bst_create_node(node);
	node->right_child_ = bst_create_node(node);
}

void bst_reduce_external(Bst_node* node, Bst* tree) {
	Bst_node* sibling = (node->parent_->left_child_ == node)
		 ? node->parent_->right_child_
		 : node->parent_->left_child_;
	Bst_node* parent = node->parent_;
	free(node);
	if(parent->parent_ == NULL)
		tree->root_ = sibling;
	else if(parent->parent_->left_child_ == parent)
		parent->parent_->left_child_ = sibling;
	else
		parent->parent_->right_child_ = sibling;
	free(parent);
}

Bst_node* bst_in_order_succ(Bst_node* node) {
	node = node->right_child_;
	while(node->left_child_!=NULL)	node = node->left_child_;
	return node;
}


Bst* bst_create_tree() {
	Bst* tree = (Bst*)malloc(sizeof(Bst));
	tree->root_ = bst_create_node(NULL);
	return tree;
}

int bst_is_empty(Bst* tree) {
	return bst_is_external(tree->root_);
}

Bst_node* bst_find_r(Bst_node* node, int item) {
	if(bst_is_external(node))
		return node;
	if(node->data_ == item)
		return node;
	else if(node->data_ > item)
		return bst_find_r(node->left_child_,item);
	else if(node->data_ < item)
		return bst_find_r(node->right_child_,item);
}

int bst_find(Bst* tree, int item) {
	Bst_node* node = bst_find_r(tree->root_,item);
	if(bst_is_external(node))
		return BST_NO_SUCH_ITEM;
	else
		return node->data_;
}

void bst_insert(Bst* tree, int item) {
	Bst_node* node = bst_find_r(tree->root_,item);
	if(bst_is_internal(node))	return;
	node->data_ = item;
	bst_expand_external(node);
}

void bst_remove(Bst* tree, int item) {
	Bst_node* node = bst_find_r(tree->root_,item);
	if(bst_is_external(node))
		return;
	Bst_node* leaf = node->left_child_;
	if(bst_is_internal(leaf))
		leaf = node->right_child_;
	if(bst_is_external(leaf))
		bst_reduce_external(leaf,tree);
	else {
		leaf = bst_in_order_succ(node);
		node->data_ = leaf->parent_->data_;
		bst_reduce_external(leaf,tree);
	}
}

void bst_test_show_r(Bst_node* node) {
	if(bst_is_external(node))	return;
	bst_test_show_r(node->left_child_);
	printf(" %d",node->data_);
	bst_test_show_r(node->right_child_);
}

void bst_test_show(Bst* tree) {
	printf("tree :");
	bst_test_show_r(tree->root_);
	printf("\n");
}