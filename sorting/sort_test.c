#include "sort_test.h"

char name_algorithm[5][20] = {"Insertion","Selection","Heapsort","Mergesort","Quicksort"};

int** list = NULL;

int select_continue() {
	int bContinue;
	printf("==================================================================================\n");
	printf("[1]continue [2]exit >> ");
	scanf("%d",&bContinue);
	return 2-bContinue;
}

void initialize_list(int size, int arranged, int duplicate) {
	for(int i=0; i<size; i++)
		list[0][i] = (arranged == REVERSE_ARRANGED) ? size-i : i+1;
	// result : pre-arranged or reverse-arranged

	if(duplicate == DUPLICATE_ALLOWED) {
		for(int i=0; i<size/4; i++) {
			int index = rand()%(size-1); // 0 ~ n-2
			list[0][index] = list[0][index+1];
		}
	}
	// result : duplicate-allowed

	int mix_time;
	switch(arranged) {
	case PRE_ARRANGED:
	case REVERSE_ARRANGED:
		mix_time=0;
		break;
	case NOT_ARRANGED:
		mix_time = size;
		break;
	case ALMOST_ARRANGED:
		mix_time = (size>100)?(size/100):2;
		break;
	}
	for(int i=0; i<mix_time; i++) {
		int i1 = rand()%size;
		int i2;
		do {	i2 = rand()%size;	} while(i1==i2);
		int tmp = list[0][i1];
		list[0][i1] = list[0][i2];
		list[0][i2] = tmp;
	}
	// result : almost-arranged or non-arranged
}

int select_list_option() {
	int size, arranged, duplicate;

	printf("==================================================================================\n");
	printf("list size >> ");
	scanf("%d",&size);
	printf("[1]Pre-Arranged [2]Not Arranged [3]Almost Arranged [4]Reverse-Arranged >> ");
	scanf("%d",&arranged);
	printf("[1]Duplicate Allowed [2]Duplicate Not Allowed >> ");
	scanf("%d",&duplicate);

	list = (int**)malloc(sizeof(int*)*5);
	for(int i=0;i<5;i++)
		list[i] = (int*)malloc(sizeof(int)*size);
	// list[0-4] memory allocation

	initialize_list(size,arranged,duplicate);
	// list[0] initialize

	for(int i=0;i<size;i++)
		for(int j=1;j<5;j++)
			list[j][i] = list[0][i];
	// list[0] -> list[1-4] copy

	return size;
}

void test_show(int size) {
	printf("[test show]\n");
	for(int algorithm=0; algorithm<5; algorithm++) {
		for(int i=0;i<5;i++)
			printf(" %d",list[algorithm][i]);
		printf(" ...");
		for(int i=5;i>0;i--)
			printf(" %d",list[algorithm][size-i]);
		printf("\n");
	}
	// print first 5 and last 5 elements of each list
}

void sort(int size) {
	void (*sort_algorithm[5])(int*,int) = {sort_insertion,sort_selection,sort_heap,sort_merge,sort_quick};
	printf("==================================================================================\n");
	printf("[runtime]\n");
	for(int i=0;i<5;i++) {
		measure_start();
		sort_algorithm[i](list[i],size);
		double time = measure_end();
		printf(" %s : %.8lfs\n",name_algorithm[i],time);
	}
	// sort each list by each sorting algorithm and measure runtime then print it 
}

void run() {
	int bContinue = TRUE;
	do {
		int size = select_list_option();
		// set list option - size arranged duplicate
		sort(size);
		// sort lists
		test_show(size);
		// test show
		for(int i=0;i<5;i++)
			free(list[i]);
		free(list);
		// memory free
	} while(select_continue());	// continue or not
}
