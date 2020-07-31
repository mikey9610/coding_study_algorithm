#ifndef SORT
#define SORT

#include <stdio.h>
#include <stdlib.h>

void sort_swap(int*,int,int);

void sort_insertion(int*,int);

void sort_selection(int*,int);

void sort_heap_recover(int*,int,int);
void sort_heap(int*,int);

void sort_merge_r(int*,int,int);
void sort_merge(int*,int);

int sort_quick_select_pivot(int*,int,int);
int sort_quick_partition(int*,int,int);
void sort_quick_r(int*,int,int);
void sort_quick(int*,int);

#endif