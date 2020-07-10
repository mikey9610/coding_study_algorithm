#include "data_structure_list.h"

// internal functions
ListNode* list_create_node(int data) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data_ = data;
    node->next_ = NULL;
    node->prev_ = NULL;
    return node;
}

void list_insert_node(List* list, ListNode* node, int pos) {
    ListNode* pVisited = list->header_;
    int count=1;

    while(pVisited->next_ != NULL && count < pos) {
        pVisited = pVisited->next_;
        count++;
    }

    pVisited->next_ = node;
    node->prev_ = pVisited;
}

void list_remove_node(List* list, ListNode* node) {
    ListNode* pPrev = node->prev_;
    pPrev->next_ = node->next_;
    if(node->next_ != NULL)
        node->next_->prev_ = pPrev;
    free(node);
}

ListNode* list_find_node(List* list, int pos) {
    ListNode* pVisited = list->header_;
    int i;
    for(i=0;i<pos;i++)
        pVisited = pVisited->next_;
    return pVisited;
}

int list_is_valid_position(List* list, int pos) {
    return pos <= list_get_size(list) && pos > 0;
}

// user interfaces
List* list_create_list() {
    List* list = (List*)malloc(sizeof(List));
    list->header_ = list_create_node(0);
    return list;
}

int list_is_empty(List* list) {
    return list->header_->next_ == NULL;
}

void list_insert_data(List* list, int data) {
    list_insert_node(list,list_create_node(data),list_get_size(list)+1);
}

void list_remove_data(List* list, int data) {
    ListNode* pVisited = list->header_;
    
    while(pVisited->next_ != NULL) {
        if(pVisited->next_->data_ == data)
            list_remove_node(list,pVisited->next_);
        else
           pVisited = pVisited->next_;
    }
}

void list_remove_pos(List* list, int pos) {
    if(list_is_valid_position(list,pos))
        list_remove_node(list,list_find_node(list,pos));
    else
        printf("error : invalid position\n");
}

void list_update_data(List* list, int from, int to) {
    ListNode* pVisited = list->header_;
    while(pVisited->next_ != NULL) {
        pVisited = pVisited->next_;
        if(pVisited->data_ == from)
            pVisited->data_ = to;
    }
}

void list_update_pos(List* list, int pos, int data) {
    if(list_is_valid_position(list,pos))
        list_find_node(list,pos)->data_ = data;
    else
        printf("error : invalid position\n");
}

int list_get_data(List* list, int pos) {
    if(list_is_valid_position(list,pos))
        return list_find_node(list,pos)->data_;
    else
        printf("error : invalid position\n");
    return 0;
}

int list_get_size(List* list) {
    ListNode* pVisited = list->header_;
    int count = 0;
    while(pVisited->next_ != NULL) {
        pVisited = pVisited->next_;
        count++;
    }
    return count;
}

int list_count_data(List* list, int data) {
    ListNode* pVisited = list->header_;
    int count=0;
    while(pVisited->next_ != NULL) {
        pVisited = pVisited->next_;
        if(pVisited->data_ == data)
            count++;
    }
    return count;
}

void list_show(List* list) {
    ListNode* pVisited = list->header_;
    printf("LIST : ");
    while(pVisited->next_ != NULL) {
        pVisited = pVisited->next_;
        printf("%d ",pVisited->data_);
    }
    printf("\n");
}

void list_initialize(List* list) {
    ListNode* pVisited = list->header_;
    while(!list_is_empty(list)) {
        list_remove_node(list,pVisited->next_);
    }
}