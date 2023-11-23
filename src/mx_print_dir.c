#include "uls.h"

void mx_print_dir(t_list** dir_list, int dir_list_len, t_list* file_list, char* flags, int flags_count, struct winsize ws){
	if (file_list != NULL && dir_list_len > 0) {
		mx_printstr("\n");
	}

    for (int i = 0; i < dir_list_len; i++) {
		t_list* current = dir_list[i];

		if (dir_list_len > 1 || (dir_list_len == 1 && file_list != NULL)) {
			mx_printstr((char *) current->data);
			mx_printstr(":");
			mx_printstr("\n");
		}

		if (current->next != NULL) {
			if (flags_count == 0) {
				mx_base_ls(current->next, ws);
			} else if (mx_is_flag(flags, flags_count, 'l')) {
				char* path = mx_strjoin(current->data, "/");
				mx_ls_l(current->next, path, false);
			}
		}

		if (i != dir_list_len - 1) {
			mx_printstr("\n");
		}
	}
}

