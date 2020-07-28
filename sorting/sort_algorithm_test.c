#include "priority_queue_array.h"
#include "priority_queue_list.h"
#include "heap_array.h"
#include "heap_tree.h"
#include "merge_sort_array.h"
#include "merge_sort_list.h"
#include "quick_sort_array.h"
#include "quick_sort_list.h"
#include "sorting_input_list.h"
#include "../timer/timer.h"

int selectMenu() {
	int nMenu;
	printf("[1]list setting [2]sort [3]exit >> ");
	scanf("%d",&nMenu);
}

void set_list_option() {
	printf("==================================================================================\n");
	printf("list size >> ");
	scanf("%d",&OPTION_SIZE);
	printf("[1]Duplicate Allowed [2]Duplicate Not Allowed >> ");
	scanf("%d",&OPTION_DUPLICATE);
	printf("[1]Pre-Arranged [2]Not Arranged [3]Almost Arranged [4]Reverse-Arranged >> ");
	scanf("%d",&OPTION_ARRANGED);
}

int set_sort_algorithm() {
	int algorithm;
	printf("==================================================================================\n");
	printf("[1]Selection [2]Insertion [3]Heap Sort [4]Merge Sort [5]Quick Sort >> ");
	scanf("%d",&algorithm);
	return algorithm;
}

int main() {
	int bFlag = TRUE;
	int nMenu, nAlgorithm;

	while(bFlag) {
		nMenu = selectMenu();
		switch(nMenu) {
		case 1:
			set_list_option();
			break;
		case 2:
			nAlgorithm = set_sort_algorithm();
			measure_start();
			switch(nAlgorithm) {
			case 1:
				break;
			}
			break;			
		case 3:
			bFlag = FALSE;
			break;
		}
	}
}