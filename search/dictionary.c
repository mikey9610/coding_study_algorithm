#include "dictionary.h"

void d_setDictionary(Dictionary* d) {
	d->capacity_ = 10;
	d->size_ = 0;
	d->array_ = (int*)malloc(sizeof(int)*d->capacity_);

	d->isEmpty = d_isEmpty;
	d->isFull = d_isFull;
	d->getSize = d_getSize;
	d->extend = d_extend;

	d->find = od_find;
	d->insert = od_insert;
	d->remove = od_remove;
}

int d_isEmpty(Dictionary* d) {
	return d->size_ == 0;
}

int d_isFull(Dictionary* d) {
	return d->size_ == d->capacity_;
}

int d_getSize(Dictionary* d) {
	return d->size_;
}

void d_extend(Dictionary* d) {
	int* new_array = (int*)malloc(sizeof(int)*d->capacity_*2);
	for(int i=0;i<d->capacity_;i++)
		new_array[i] = d->array_[i];
	d->capacity_ *= 2;
	free(d->array_);
	d->array_ = new_array;
}

int od_binarySearch(Dictionary* d, int item, int start, int end) {
	if(start>end)	return D_NO_SUCH_ITEM;
	int mid = (start+end)/2;
	if(item == d->array_[mid])
		return mid;
	else if(item < d->array_[mid])
		return od_binarySearch(d,item,start,mid-1);
	else if(item > d->array_[mid])
		return od_binarySearch(d,item,mid+1,end);
}

int od_find(Dictionary* d, int item) {
	return od_binarySearch(d,item,0,d->size_-1);
}

void od_insert(Dictionary* d, int item) {
	if(d->isFull(d))	d->extend(d);
	if(d->isEmpty(d)) {
		d->array_[0] = item;
		d->size_++;
		return;
	}	
	for(int i=0;i<d->size_;i++) {
		if(d->array_[i] > item) {
			for(int j=d->size_;j>i;j--)
				d->array_[j] = d->array_[j-1];
			d->array_[i] = item;
			d->size_++;
			return;
		}
	}
	d->array_[d->size_] = item;
	d->size_++;
}

void od_remove(Dictionary* d, int item) {
	int index = od_binarySearch(d,item,0,d->size_);
	
	if(index == D_NO_SUCH_ITEM)	return;

	for(int i=index;i<d->size_-1;i++)
		d->array_[i] = d->array_[i+1];
	d->size_--;
}

int ud_find(Dictionary* d, int item) {
	for(int i=0;i<d->size_;i++)
		if(d->array_[i]==item)
			return item;
	return D_NO_SUCH_ITEM;
}

void ud_insert(Dictionary* d, int item) {
	if(d->isFull(d))	d->extend(d);
	d->array_[d->size_] = item;
	d->size_++;
}

void ud_remove(Dictionary* d, int item) {
	if(d->isEmpty(d))	return;
	for(int i=0;i<d->size_;i++) {
		if(d->array_[i]==item) {
			for(int j=i;j<d->size_-1;j++)
				d->array_[j] = d->array_[j+1];
			d->size_--;
			return;
		}
	}
}