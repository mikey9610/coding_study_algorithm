#ifndef LINKED_LIST
#define LINKED_LIST

#include "../basic_tools.h"

typedef struct list_node_ {
	int data_;

	struct list_node_* next_;

} ListNode ;

typedef ListNode* List;

List list_new();

int list_is_empty(List);

int list_get_size(List);

void list_insert(List,int);

int list_remove(List);

ListNode* list_get_node(List,int);

void list_show(List);

#endif