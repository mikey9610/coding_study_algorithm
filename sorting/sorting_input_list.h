#ifndef SORTING_INPUT_LIST
#define SORTING_INPUT_LIST

#include "../basic_tools.h"

#define PRE_ARRANGED		0
#define NOT_ARRANGED		1
#define ALMOST_ARRANGED		2
#define REVERSE_ARRANGED	3

#define DUPLICATE_ALLOWED		1
#define DUPLICATE_NOT_ALLOWED	0	

int* input_list = NULL;

int OPTION_SIZE = 10000;
int OPTION_ARRANGED = NOT_ARRANGED;
int OPTION_DUPLICATE = DUPLICATE_NOT_ALLOWED;

void initialize_input_list();
void test_show_input_list(int start_index, int end_index);

#endif