#include "merge_sort_list.h"

void ms_list_sort(List list) {
	list_show(list);
	getchar();

	if(list_get_size(list) < 2)	return;

	// partition
	List list2 = ms_list_partition(list);
	
	// sort
	ms_list_sort(list);
	ms_list_sort(list2);

	// merge
	list = ms_list_merge(list,list2);
}

List ms_list_merge(List list1, List list2) {
	List list = list_new();
	printf("====================\n");
	list_show(list1);
	printf("+\n");
	list_show(list2);
	while(!list_is_empty(list1) && !list_is_empty(list2)) {
		if(list1->next_->data_ > list2->next_->data_)
			list_insert(list,list_remove(list1));
		else
			list_insert(list,list_remove(list2));
	}
	while(!list_is_empty(list1))
		list_insert(list,list_remove(list1));
	while(!list_is_empty(list2))
		list_insert(list,list_remove(list2));
	printf("merge ");
	list_show(list);
	printf("====================\n");
	return list;
}

List ms_list_partition(List list) {
	List tmp = list_get_node(list,list_get_size(list)/2);
	List list2 = list_new();
	list2->next_ = tmp->next_;
	tmp->next_ = NULL;
	return list2;
}