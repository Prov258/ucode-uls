#include "uls.h"

void mx_print_dir(t_list** dir_list, int dir_list_len, char* flags, int flags_count, struct winsize ws){
    for (int i = 0; i < dir_list_len; i++) {
		t_list* current = dir_list[i];

		if (dir_list_len > 1) {
			mx_printstr((char *) current->data);
			mx_printstr(":");

			if (current->next != NULL) {
				mx_printstr("\n");
			}
		}

		if (current->next != NULL) {
			if (flags_count == 0) {
				mx_base_ls(current->next, ws);
			} else if (mx_is_flag(flags, flags_count, 'l')) {
				char* path = mx_strjoin(current->data, "/");
				mx_ls_l(current->next, path);
			}
		}

		if (i != dir_list_len - 1) {
			mx_printstr("\n");
		}
	}
}

