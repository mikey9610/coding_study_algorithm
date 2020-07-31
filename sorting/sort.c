#include "sort.h"

void sort_swap(int* list, int i1, int i2) {
	int tmp = list[i1];
	list[i1] = list[i2];
	list[i2] = tmp;
}

void sort_insertion(int* list, int size) {
	int i,j,tmp;
	for(i=1;i<size;i++) {
		tmp = list[i];		
		for(j=0;j<i&&list[j]>list[i];j++);
		for(int k=i;k>j;k--)	list[k] = list[k-1];
		list[j] = tmp;
	}
}

void sort_selection(int* list, int size) {
	for(int i=0;i<size-1;i++) {
		int max = i;
		for(int j=i+1;j<size;j++)
			if(list[j]>list[max])
				max = j;
		sort_swap(list,i,max);
	}
}

void sort_heap_recover(int* list, int size, int index) {
	if(size < index*2)	return;
	// if external, return

	int smaller = index*2;
	// smaller = left child
	if(size >= index*2+1)
		if(list[smaller-1] > list[index*2])
			smaller = index*2+1;
	// if rigth child exists and right child < left child, smaller = right child

	if(list[index-1] <= list[smaller-1])	return;
	// if index < smaller, return

	sort_swap(list,index-1,smaller-1);
	// swap
	
	sort_heap_recover(list,size,smaller);
	// recursive
}

void sort_heap(int* list, int size) {
	for(int i=size/2;i>0;i--)
		sort_heap_recover(list,size,i);
	for(int i=size-1;i>0;i--) {
		sort_swap(list,0,i);
		sort_heap_recover(list,i,1);
	}
}

void sort_merge_r(int* list, int start, int end) {
	if(start == end)	return;
	// single element

	int mid = (start+end+1)/2;
	sort_merge_r(list,start,mid-1);
	sort_merge_r(list,mid,end);
	// partition & sort

	int i1 = start, i2 = mid;
	while(i1 != i2 && i2 != end+1) {
		if(list[i1] < list[i2]) {
			int item = list[i2];
			for(int i=i2;i>i1;i--)
				list[i] = list[i-1];
			list[i1] = item;
			i2++;
		}
		i1++;
	}
	// merge
}

void sort_merge(int* list, int size) {
	sort_merge_r(list,0,size-1);
}

int sort_quick_select_pivot(int* list, int start, int end) {
	int pivot[3],index[3];
	for(int i=0;i<3;i++) {
		index[i] = rand()%(end-start+1)/2+start;
		pivot[i] = list[index[i]];
	}
	// generate 3 pivot index randomly
	
	sort_insertion(pivot,3);
	// sort 3 pivot values
	
	for(int i=0;i<3;i++)
		if(list[index[i]]==pivot[1])
			return index[i];
	// return pivot index whose value is median value among 3
}

int sort_quick_partition(int* list, int start, int end) {
	sort_swap(list,start,sort_quick_select_pivot(list,start,end));
	// select pivot and keep in list[start]

	for(int low=start+1,high=end;;low++,high--) {
		while(low <= end && list[low] > list[start])
			low++;
		while(list[high] < list[start])
			high--;
		if(high > low)
			sort_swap(list,low,high);
		else {
			sort_swap(list,start,high);
			return high;
		}
	}
	// partition
}

void sort_quick_r(int* list, int start, int end) {
	if(start >= end)	return;
	// single or no element

	int mid = sort_quick_partition(list,start,end);
	// partition

	sort_quick_r(list,start,mid-1);
	sort_quick_r(list,mid+1,end);
	// recursive
}

void sort_quick(int* list, int size) {
	sort_quick_r(list,0,size-1);
}