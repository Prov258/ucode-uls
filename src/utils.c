#include <uls.h>

bool mx_list_cmp(void* a, void* b) {
	return mx_strcmp((char *) a, (char *) b) > 0;
}

int mx_find_max_name_len(t_list* list) {
	int max = 0;

	while (list != NULL) {
		int len = mx_strlen((char *) list->data);
		if (len > max) {
			max = len;
		}
		list = list->next;
	}

	return max;
}

t_list* mx_get_elem_in_list(t_list* list, int index) {
	int i = 0;

	while (list != NULL) {
		if (i == index) {
			return list;
		}
		list = list->next;
		i++;
	}

	return NULL;
}

