#include "merge_sort_array.h"

void ms_array_sort(int* list, int start, int end) {
	if(end-start < 1)	return;
	
	// partition
	int middle = ms_array_partition(start,end);

	// sort
	ms_array_sort(list,start,middle-1);
	ms_array_sort(list,middle,end);

	// merge
	ms_array_merge(list,start,end);
}

void ms_array_merge(int* list, int start, int end) {
	int i1 = start, i2 = ms_array_partition(start,end);
	int i;

	while(i1 != i2 && i2 != end+1) {
		if(list[i1] < list[i2]) {
			int item = list[i2];
			for(i=i2;i>i1;i--)
				list[i] = list[i-1];
			list[i1] = item;
			i2++;
		}
		i1++;
	}
}

int ms_array_partition(int start, int end) {
	return start + (end-start+1)/2;
}