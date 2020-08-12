#include "hash_table.h"

HashTable* HT_setHashTable(int size) {
	HashTable* table = (HashTable*)malloc(sizeof(HashTable));
	table->size_ = size;
	table->bucket_array_ = (HT_BUCKET**)malloc(sizeof(HT_BUCKET*)*size);
	for(int i=0;i<size;i++)	table->bucket_array_[i] = NULL;
	return table;
}

void HT_insert(HashTable* table, int key) {
	int index = HT_hash(table->size_,key);

	// separate chaining
	if(table->bucket_array_[index] == NULL)	table->bucket_array_[index] = HT_expandBucketList(key);
	else {
		HT_BUCKET* pVisited = table->bucket_array_[index];
		while(pVisited->link_!=NULL)	pVisited = pVisited->link_;
		pVisited->link_ = HT_expandBucketList(key);
	}

	// open addressing

}

void HT_remove(HashTable* table, int key) {
	int index = HT_hash(table->size_,key);
	
	// separate chaining
	HT_BUCKET* pVisited = table->bucket_array_[index];
	HT_BUCKET* pPrev = NULL;
	printf("1");
	while(pVisited!=NULL && pVisited->data_!=key) {
		pPrev = pVisited;
		pVisited = pVisited->link_;
	}
	printf("2");
	if(pVisited == NULL)	return;	// no such item
	printf("3");	
	if(pPrev == NULL)
		table->bucket_array_[index] = pVisited->link_;
	else
		pPrev->link_ = pVisited->link_;
	printf("4");	
	free(pVisited);	

	// open addressing
}

HT_BUCKET* HT_find(HashTable* table, int key) {
	int index = HT_hash(table->size_,key);
	
	// separate chaining
	HT_BUCKET* pVisited = table->bucket_array_[index];

	while(pVisited!=NULL && pVisited->data_!=key)	pVisited = pVisited->link_;

	return pVisited;	// no such item
	
	// open addressing
}

int HT_hashCodeMap(int key) {	return key;	}
int HT_compressionMap(int size, int hashCode) {	return hashCode%size;	}

int HT_hash(int size, int key) {	return HT_compressionMap(size,HT_hashCodeMap(key));	}

void HT_test_show(HashTable* table) {
	for(int i=0;i<table->size_;i++) {
		printf("[ %d ] : ",i);
		HT_BUCKET* bucket = table->bucket_array_[i];
		if(bucket == NULL)	printf("EMPTY\n");
		else {
			while(bucket != NULL) {
				printf("%d ",bucket->data_);
				bucket = bucket->link_;
			}
			printf("\n");
		}
	}
}

HT_BUCKET* HT_expandBucketList(int key) {
	HT_BUCKET* bucket = (HT_BUCKET*)malloc(sizeof(HT_BUCKET));
	bucket->link_ = NULL;
	bucket->data_ = key;
	return bucket;
}