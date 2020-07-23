#include "sorting_input_list.h"

void initialize_input_list(int arranged, int duplicate) {
	for(int i=0; i<INPUT_LIST_SIZE; i++) {
		if(arranged == REVERSE_ARRANGED)
			input_list[i] = INPUT_LIST_SIZE-i;
		else
			input_list[i] = i+1;
	}
	// result : pre-arranged or reverse-arranged

	if(duplicate) {
		for(int i=0; i<INPUT_LIST_SIZE/4; i++) {
			int index = rand()%(INPUT_LIST_SIZE-1);
			input_list[index] = input_list[index+1];
		}
	}
	// result : duplicate-allowed

	int mix_time;
	switch(arranged) {
	case PRE_ARRANGED:
	case REVERSE_ARRANGED:
		mix_time=0;
		break;
	case NON_ARRANGED:
		mix_time = INPUT_LIST_SIZE;
		break;
	case ALMOST_ARRANGED:
		mix_time = (INPUT_LIST_SIZE>100)?(INPUT_LIST_SIZE/100):1;
		break;
	}
	for(int i=0; i<mix_time; i++) {
		int i1 = rand()%INPUT_LIST_SIZE;
		int i2;
		do {	i2 = rand()%INPUT_LIST_SIZE;	} while(i1==i2);
		int tmp = input_list[i1];
		input_list[i1] = input_list[i2];
		input_list[i2] = tmp;
	}
	// result : almost-arranged or non-arranged
}

void test_show_input_list(int max) {
	for(int i=0;i<max+1;i++)
		printf(" %d",input_list[i]);
	printf("\n");
}