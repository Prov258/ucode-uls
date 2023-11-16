#include <uls.h>

void mx_print_dir(t_list** dir_list, int dir_list_len){
	struct winsize ws;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);

    for (int i = 0; i < dir_list_len; i++) {
		t_list* current = dir_list[i];

		if (dir_list_len > 1) {
			mx_printstr((char *) current->data);
			mx_printstr(":");
		}

		if (current->next != NULL) {
			if (dir_list_len > 1) {
				mx_printstr("\n");
			}

			current = current->next;
			int max_name_len = mx_find_max_name_len(current) + 2;
			int elements_count = mx_list_size(current);
			int cols = ws.ws_col / max_name_len;
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

					if (k != cols - 1) {
						mx_printstr("  ");
					}
				}

				if (j != rows - 1) {
					mx_printstr("\n");
				}
			}
		}

		mx_printstr("\n");

		if (i != dir_list_len - 1) {
			mx_printstr("\n");
		}
	}
}
