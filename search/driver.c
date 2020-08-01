#include "binary_search_tree.h"

int main() {
	Bst* tree = bst_create_tree();

	tree->insert(tree,1);
	tree->insert(tree,5);
	tree->insert(tree,7);
	tree->insert(tree,11);
	tree->insert(tree,95);
	tree->insert(tree,0);
	tree->insert(tree,4);
	tree->insert(tree,33);
	tree->insert(tree,22);
	tree->insert(tree,80);
	tree->insert(tree,66);
	tree->insert(tree,56);


	bst_test_show(tree);
	getchar();
	return 0;
}