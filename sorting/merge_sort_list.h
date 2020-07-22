#ifndef MERGE_SORT_LIST
#define MERGE_SORT_LIST

#include "../basic_tools.h"
#include "../data_structure/linked_list.h"

void ms_list_sort(List);
List ms_list_merge(List,List);
List ms_list_partition(List);

#endif