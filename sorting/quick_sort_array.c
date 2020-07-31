#include "quick_sort_array.h"
	
int qs_array_partition(int* list, int start, int end) {
	// non-duplicate ver
	qs_array_swap(list,start,qs_array_get_pivot_index(list,start,end));
	int pivot = list[start];
	
	for(int low=start+1,high=end;;low++,high--) {
		while(low <= end && list[low] < pivot)
			low++;

		while(list[high] > pivot)
			high--;

		if(high > low) {
			qs_array_swap(list,low,high);
		}
		else {
			qs_array_swap(list,start,high);
			return high;
		}
	}
	

//	duplicate ver
/*
	qs_array_swap(list,start,qs_array_get_pivot_index(list,start,end));
	int pivot = list[start];
	
	int equal_l = 0;
	int equal_r = 0;
	int low = start+1;
	int high = end;
	int count=0;

	while(1) {
	for(int i=0;i<30;i++)
		printf("%d ",list[i]);
	printf("\n");
		while(low+equal_l < high-equal_r && list[low+equal_l] <= pivot) {
			if(list[low+equal_l] == pivot) {
				while(list[low+equal_l] == pivot)	equal_l++;
				while(list[low+equal_l+count] < pivot)	count++;
				for(int i=0;i<count;i++)
					list[low+i] = list[low+equal_l+i]; 
				low += count;
				count = 0;
			}
			else
				low++;
		}		

	for(int i=0;i<low-1;i++)
		printf("  ");
	if(equal_l!=0) {
		printf("l ");	
	}else printf("  ");
	for(int i=0;i<equal_l;i++)
		printf("  ");
	printf("L ");	

		while(high-equal_r > low+equal_l && list[high-equal_r] >= pivot) {
			if(list[high-equal_r] == pivot) {
				while(list[high-equal_r] == pivot)	equal_r++;
				while(list[high-equal_r-count] > pivot)	count++;
				for(int i=0;i<count;i++)
					list[high-i] = list[high-equal_r-i]; 
				high -= count;
				count = 0;
			}
			else
				high--;
		}
	if(equal_l==0)
	printf("  ");
	for(int i=0;i<(high-equal_r)-(low+equal_l)-2;i++)
		printf("  ");
	printf("H ");
	if(equal_r!=0) {
	for(int i=0;i<equal_r-1;i++)
		printf("  ");
	printf("h");
	}
	printf("\n");
		if((high-equal_r)-(low+equal_l) <= 1) {
			qs_array_swap(list,low,start);
			for(int i=1;i<=equal_l;i++)	list[low+i] = pivot;
			for(int i=1;i<=equal_r;i++)	list[high-i] = pivot;
			break;
		}
		else {
			qs_array_swap(list,low+equal_l,high-equal_r);
			low++;
			high--;
		}
	}
	int* index = (int*)malloc(sizeof(int)*2);
	index[0] = low+equal_l;
	index[1] = high-equal_r;
	return index;
*/
}

void qs_array_sort(int* list, int start, int end) {
	if(start >= end)	return;
	
	// non-duplicate ver
	int index = qs_array_partition(list,start,end);

	qs_array_sort(list,start,index-1);
	qs_array_sort(list,index+1,end);
	
	// duplicate ver
}

int qs_array_get_pivot_index(int* list, int start, int end) {
	// pivot first element ver
	return start;
}

void qs_array_swap(int* list, int i1, int i2) {
	int tmp = list[i1];
	list[i1] = list[i2];
	list[i2] = tmp;
}