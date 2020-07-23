#ifndef QUICK_SORT_ARRAY
#define QUICK_SORT_ARRAY

#include "../basic_tools.h"

int qs_array_partition(int*,int,int);
void qs_array_sort(int*,int,int);
int qs_array_get_pivot_index(int*,int,int);
void qs_array_swap(int*,int,int);

#endif