#include "dictionary.h"
#include "../basic_tools.h"

int main() {
	Dictionary dictionary;

	d_setDictionary(&dictionary);

	dictionary.insert(&dictionary,1);
	dictionary.insert(&dictionary,5);
	dictionary.insert(&dictionary,6);
	dictionary.insert(&dictionary,8);
	dictionary.insert(&dictionary,2);
	dictionary.insert(&dictionary,4);

	for(int i=0;i<dictionary.size_;i++)
		printf(" %d",dictionary.array_[i]);
	
	dictionary.remove(&dictionary,5);
	dictionary.remove(&dictionary,4);
	dictionary.remove(&dictionary,3);
	dictionary.remove(&dictionary,2);
	printf("\n");

	for(int i=0;i<dictionary.size_;i++)
		printf(" %d",dictionary.array_[i]);

	printf("\n");
	printf(" %d\n",dictionary.find(&dictionary,1));
	printf(" %d\n",dictionary.find(&dictionary,6));
	printf(" %d\n",dictionary.find(&dictionary,10));

	return 0;
}