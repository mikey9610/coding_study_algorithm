#include "sorting_input_list.h"

void initialize_input_list() {
	if(input_list == NULL)	free(input_list);
	input_list = (int*)malloc(sizeof(int)*OPTION_SIZE);
	// result : sized

	for(int i=0; i<OPTION_SIZE; i++)
			input_list[i] = (OPTION_ARRANGED == REVERSE_ARRANGED) ? OPTION_SIZE-i : i+1;
	// result : pre-arranged or reverse-arranged

	if(OPTION_DUPLICATE) {
		for(int i=0; i<OPTION_SIZE/4; i++) {
			int index = rand()%(OPTION_SIZE-1); // 0 ~ n-2
			input_list[index] = input_list[index+1];
		}
	}
	// result : duplicate-allowed

	int mix_time;
	switch(OPTION_ARRANGED) {
	case PRE_ARRANGED:
	case REVERSE_ARRANGED:
		mix_time=0;
		break;
	case NOT_ARRANGED:
		mix_time = OPTION_SIZE;
		break;
	case ALMOST_ARRANGED:
		mix_time = (OPTION_SIZE>100)?(OPTION_SIZE/100):2;
		break;
	}
	for(int i=0; i<mix_time; i++) {
		int i1 = rand()%OPTION_SIZE;
		int i2;
		do {	i2 = rand()%OPTION_SIZE;	} while(i1==i2);
		int tmp = input_list[i1];
		input_list[i1] = input_list[i2];
		input_list[i2] = tmp;
	}
	// result : almost-arranged or non-arranged
}

void test_show_input_list(int start_index, int end_index) {
	printf("test show :");
	for(int i=start_index;i<=end_index;i++)
		printf(" %d",input_list[i]);
	printf("\n");
}