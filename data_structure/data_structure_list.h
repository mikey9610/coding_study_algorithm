#ifndef DATA_STRUCTURE_LIST_
#define DATA_STRUCTURE_LIST_

#include "basic_tools.h"

typedef struct _ListNode {
    // DATA FIELD
    int data_;

    // LINK FIELD
    struct _ListNode* next_;
    struct _ListNode* prev_;

} ListNode ;

typedef struct _List {
    ListNode* header_;

} List ;

// internal functions
ListNode* list_create_node(int data);
void list_insert_node(List* list, ListNode* node, int pos);
void list_remove_node(List* list, ListNode* node);
ListNode* list_find_node(List* list, int pos);
int list_is_valid_position(List* list, int pos);

// user interfaces
List* list_create_list();   // return new empty list
int list_is_empty(List* list);  // return whether list is empty or not
void list_insert_data(List* list, int data);    // insert new data into list
void list_remove_data(List* list, int data);    // remove existing data with specific data out of list
void list_remove_pos(List* list, int pos);      // remove existing data with specific position out of list
void list_update_data(List* list, int from, int to);    // update exisitng data with specific data into new data
void list_update_pos(List* list, int pos, int data);    // update existing data with specific position into new data
int list_get_data(List* list, int pos); // return existing data with specific position
int list_get_size(List* list);  // return list size
int list_count_data(List* list, int data);  // count how many specific data exist in list
void list_show(List* list);     // show all data in list
void list_initialize(List* list); // initialize list

#endif