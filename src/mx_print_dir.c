#include <uls.h>

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

void mx_base_ls(t_list* current, int dir_list_len, struct winsize ws) {
	if (dir_list_len > 1) {
		mx_printstr("\n");
	}

	current = current->next;
	int max_name_len = mx_find_max_name_len(current);
	int elements_count = mx_list_size(current);
	int cols = mx_count_cols(ws.ws_col, max_name_len);
	// int cols = ws.ws_col / max_name_len;
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

			for (int c = 0; c < max_name_len - mx_strlen((char *) elem_to_print->data); c++) {
				mx_printstr(" ");
			}

			if (k != cols - 1) {
				mx_printstr("  ");
			}
		}

		if (j != rows - 1) {
			mx_printstr("\n");
		}
	}
}

void mx_ls_l(t_list* current) {
	mx_printstr("hello");
	mx_printstr((char *) current->data);
}

void mx_print_dir(t_list** dir_list, int dir_list_len, char* flags, int flags_count){
	struct winsize ws;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);

    for (int i = 0; i < dir_list_len; i++) {
		t_list* current = dir_list[i];

		if (dir_list_len > 1) {
			mx_printstr((char *) current->data);
			mx_printstr(":");
		}

		if (current->next != NULL) {
			if (flags_count == 0) {
				mx_base_ls(current, dir_list_len, ws);
			} else if (mx_is_flag(flags, flags_count, 'l')) {
				mx_ls_l(current);
			}
		}

		mx_printstr("\n");

		if (i != dir_list_len - 1) {
			mx_printstr("\n");
		}
	}
}
