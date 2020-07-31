#include "sort_test.h"

char name_algorithm[5][20] = {"Insertion","Selection","Heapsort","Mergesort","Quicksort"};

int select_continue() {
	int bContinue;
	printf("[1]continue [2]exit >> ");
	scanf("%d",&bContinue);
	return 2-bContinue;
}

int select_list_size() {
	int size;
	printf("list size >> ");
	scanf("%d",&size);
	return size;
}

int select_list_arranged() {
	int arranged;
	printf("[1]Pre-Arranged [2]Not Arranged [3]Almost Arranged [4]Reverse-Arranged >> ");
	scanf("%d",&arranged);
	return arranged;
}

int select_list_duplicate() {
	int duplicate;
	printf("[1]Duplicate Allowed [2]Duplicate Not Allowed >> ");
	scanf("%d",&duplicate);
	return duplicate;
}

int* initialize_list(int size, int arranged, int duplicate) {
	int* list = (int*)malloc(sizeof(int)*size);
	// sized list

	for(int i=0; i<size; i++)
		list[i] = (arranged == REVERSE_ARRANGED) ? i+1 : size-i;
	// result : pre-arranged or reverse-arranged

	if(duplicate == DUPLICATE_ALLOWED) {
		for(int i=0; i<size/4; i++) {
			int index = rand()%(size-1); // 0 ~ n-2
			list[index] = list[index+1];
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
		int j;
		do {	j = rand()%size;	} while(i==j);
		sort_swap(list,i,j);
	}
	// result : almost-arranged or non-arranged

	return list;
}

int* copy_list(int* original, int size) {
	int* copy = (int*)malloc(sizeof(int)*size);
	for(int i=0;i<size;i++)	copy[i] = original[i];
	return copy;
}

void test_show(int* list, int size) {
	for(int i=0;i<5;i++)
		printf(" %d",list[i]);
	printf(" ...");
	for(int i=5;i>0;i--)
		printf(" %d",list[size-i]);
	printf("\n");
	// print first 5 and last 5 elements of list
}

void run() {
	void (*sort_algorithm[5])(int*,int) = {sort_insertion,sort_selection,sort_heap,sort_merge,sort_quick};
	int bContinue = TRUE;
	
	srand(time(NULL));

	do {
		printf("================================================\n");
		int size = select_list_size();
		int arranged = select_list_arranged();
		int duplicate = select_list_duplicate();
		// select list option - size / arranged / duplicate

		int* list = initialize_list(size,arranged,duplicate);
		// initialize list with settings above

		printf("================================================\n");
		printf("initial list : ");
		test_show(list,size);
		for(int i=0;i<5;i++) {
			int* copylist = copy_list(list,size);
			printf("[ %s ]\n",name_algorithm[i]);
			measure_start();
			sort_algorithm[i](copylist,size);
			double time = measure_end();
			printf(" - runtime : %.8lfs\n",time/1000.0);
			printf(" - test show :");
			test_show(copylist,size);
			free(copylist);
		}
		free(list);
		printf("================================================\n");
	} while(select_continue());	// continue or not
}