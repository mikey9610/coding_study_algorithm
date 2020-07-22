#include "merge_sort_array.h"
#include "time.h"

int main() {
	srand(time(NULL));

	int list[20];

	for(int i=0;i<20;i++)
		list[i] = rand()%10;

	for(int i=0;i<20;i++)
		printf("%d ",list[i]);
	printf("\n");
	
	ms_array_sort(list,0,19);

	for(int i=0;i<20;i++)
		printf("%d ",list[i]);
	printf("\n");


    return 0;
}