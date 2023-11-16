#include <uls.h>

void mx_print_dir(t_list** dir_list, int dir_list_len){
    for (int i = 0; i < dir_list_len; i++) {
		t_list* current = dir_list[i];

		mx_printstr((char *) current->data);
		mx_printstr(":");

		if (current->next != NULL) {
			mx_printstr("\n");
			current = current->next;

			while (current != NULL) {
				mx_printstr((char *) current->data);
				mx_printstr(" ");
				current = current->next;
			}
		}

		mx_printstr("\n");

		if (i != dir_list_len - 1) {
			mx_printstr("\n");
		}
	}
}
