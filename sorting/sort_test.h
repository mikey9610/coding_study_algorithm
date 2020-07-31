#ifndef SORT_TEST
#define SORT_TEST

#include <stdio.h>
#include <time.h>

#include "sort.h"
#include "../timer/timer.h"

#define PRE_ARRANGED		1
#define NOT_ARRANGED		2
#define ALMOST_ARRANGED		3
#define REVERSE_ARRANGED	4

#define DUPLICATE_ALLOWED		1
#define DUPLICATE_NOT_ALLOWED	2	

int select_continue();

int select_list_size();
int select_list_arranged();
int select_list_duplicate();

int* initialize_list(int,int,int);
int* copy_list(int*,int);

void run();

#endif