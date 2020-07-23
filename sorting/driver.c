#include "quick_sort_array.h"
#include "sorting_input_list.h"

int main() {
	
	//initialize_input_list(NON_ARRANGED,DUPLICATE_NOT_ALLOWED);
	//test_show_input_list(INPUT_LIST_SIZE-1);
	
	int arr[20];
	for(int i=19;i>=0;i--)
		arr[i] = i+1;

	for(int i=0;i<20;i++)
		printf("%d ",arr[i]);
	printf("\n");

	qs_array_sort(arr,0,19);

	for(int i=0;i<20;i++)
		printf("%d ",arr[i]);
	printf("\n");
	
	//test_show_input_list(INPUT_LIST_SIZE-1);
	


    return 0;
}