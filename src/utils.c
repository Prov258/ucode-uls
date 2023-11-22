#include <uls.h>

bool mx_is_flag(char* flags, int n, char flag) {
	for (int i = 0; i < n; i++) {
		if (flags[i] == flag) {
			return true;
		}
	}

	return false;
}

int mx_count_cols(int width, int max_len) {
	int cols = 0;

	while (width >= max_len) {
		width -= max_len;
		cols++;

		if (cols == 1) {
			max_len += 2;
		}
	}

	return cols;
}

bool mx_list_cmp(void* a, void* b) {
	return mx_strcmp((char *) a, (char *) b) > 0;
}

int mx_ceil_division(int a, int b) {
	return (a / b) + ((a % b) != 0);
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
	if (max % 8 == 0) {
		max += 8;
	}
	else {
		max = 8 - (max % 8) + max;
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

