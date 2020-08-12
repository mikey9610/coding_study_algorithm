#ifndef HASH_TABLE
#define HASH_TABLE

#include <stdio.h>
#include <stdlib.h>

typedef struct _hash_table_bucket {
	int data_;
	struct _hash_table_bucket* link_;
} HT_BUCKET ;

typedef struct _hash_table {
	int size_;
	HT_BUCKET** bucket_array_;
} HashTable ;

HashTable* HT_setHashTable(int);

void HT_insert(HashTable*,int);
void HT_remove(HashTable*,int);
HT_BUCKET* HT_find(HashTable*,int);

int HT_hashCodeMap(int);
int HT_compressionMap(int,int);

int HT_hash(int,int);

void HT_test_show(HashTable*);

HT_BUCKET* HT_expandBucketList(int); 


#endif