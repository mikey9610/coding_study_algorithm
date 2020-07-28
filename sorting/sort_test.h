#ifndef SORT_TEST
#define SORT_TEST

#include "sort.h"
#include "../timer/timer.h"
#include "../basic_tools.h"

#define PRE_ARRANGED		1
#define NOT_ARRANGED		2
#define ALMOST_ARRANGED		3
#define REVERSE_ARRANGED	4

#define DUPLICATE_ALLOWED		1
#define DUPLICATE_NOT_ALLOWED	2	

int select_continue();
void initialize_list(int,int,int);
int select_list_option();
void test_show(int) ;
void sort(int);
void run();

#endif