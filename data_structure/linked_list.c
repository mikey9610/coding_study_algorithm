#include "linked_list.h"

List list_new() {
	List list = (ListNode*)malloc(sizeof(ListNode));
	list->next_ = NULL;
	return list;
}

int list_is_empty(List list) {
	return list->next_ == NULL;
}

int list_get_size(List list) {
	ListNode* node = list->next_;
	int count = 0;
	while(node != NULL) {
		node = node->next_;
		count++;
	}
	return count;
}

void list_insert(List list, int item) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data_ = item;
	node->next_ = NULL;

	if(list->next_ == NULL)
		list->next_ = node;
	else {
		ListNode* tmp = list->next_;
		while(tmp->next_ != NULL)
			tmp = tmp->next_;
		tmp->next_ = node;
	}
}

int list_remove(List list) {
	if(list_is_empty(list))
		return -1;
	ListNode* tmp = list->next_;
	int item = tmp->data_;
	list->next_ = tmp->next_;
	free(tmp);
	return item;
}

ListNode* list_get_node(List list, int pos) {
	if(list_get_size(list) < pos || pos < 0)
		return NULL;
	ListNode* tmp = list;
	for(int i=0;i<pos;i++)
		tmp = tmp->next_;
	return tmp;
}

void list_show(List list) {
	ListNode* tmp = list->next_;
	printf("List : ");
	while(tmp != NULL) {
		printf("%d ",tmp->data_);
		tmp = tmp->next_;
	}
	printf("\n");
}