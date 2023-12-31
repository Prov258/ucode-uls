#include "uls.h"

void mx_print_files(t_list* current, struct winsize ws){
	if (isatty(STDOUT_FILENO) == 1) {
		int max_name_len = mx_find_max_name_len(current);
		int elements_count = mx_list_size(current);
		int cols = mx_count_cols(ws.ws_col, max_name_len);
		int rows = elements_count / cols;
		if (elements_count % cols != 0) {
			rows++;
		}

		for (int j = 0; j < rows; j++) {
			for (int k = 0; k < cols; k++) {
				t_list* elem_to_print = mx_get_elem_in_list(current, (rows * k) + j);
				if (elem_to_print == NULL) {
					continue;
				}

				mx_printstr((char *) elem_to_print->data);

				int tabs_count = mx_ceil_division((max_name_len - mx_strlen((char *) elem_to_print->data)), 8);
				for (int c = 0; c < tabs_count; c++) {
					if (k != cols - 1) {
						mx_printstr("\t");
					}
				}
			}

			mx_printstr("\n");
		}
	} else {
		while (current != NULL) {
			mx_printstr((char *) current->data);
			mx_printstr("\n");
			current = current->next;
		}
	}
}

