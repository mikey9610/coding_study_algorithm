#ifndef SORTING_INPUT_LIST
#define SORTING_INPUT_LIST

#include "../basic_tools.h"

#define INPUT_LIST_SIZE 10

#define PRE_ARRANGED		0
#define NON_ARRANGED		1
#define ALMOST_ARRANGED		2
#define REVERSE_ARRANGED	3

#define DUPLICATE_ALLOWED		1
#define DUPLICATE_NOT_ALLOWED	0	

int input_list[INPUT_LIST_SIZE];

void initialize_input_list(int,int);
void test_show_input_list(int);

#endif