#ifndef DICTIONARY
#define DICTIONARY

#include "../basic_tools.h"

#define D_NO_SUCH_ITEM -1

typedef struct _dictionary Dictionary;

void d_setDictionary(Dictionary*);

int d_isEmpty(Dictionary*);
int d_isFull(Dictionary*);
int d_getSize(Dictionary*);
void d_extend(Dictionary*);

int od_binarySearch(Dictionary*,int,int,int);
int od_find(Dictionary*,int);
void od_insert(Dictionary*,int);
void od_remove(Dictionary*,int);

int ud_find(Dictionary*,int);
void ud_insert(Dictionary*,int);
void ud_remove(Dictionary*,int);

struct _dictionary {	
	int size_;
	int capacity_;
	int* array_;

	int (*isEmpty)(Dictionary*);
	int (*isFull)(Dictionary*);
	int (*getSize)(Dictionary*);
	void (*extend)(Dictionary*);

	int (*find)(Dictionary*,int);
	void (*insert)(Dictionary*,int);
	void (*remove)(Dictionary*,int);
};

#endif