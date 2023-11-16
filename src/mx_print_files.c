#include <uls.h>

void mx_print_files(int dir_len, t_list* file_list){
    t_list* temp = file_list;

	while (temp != NULL) {
		mx_printstr((char *) temp->data);
		if (temp->next != NULL) {
			mx_printstr(" ");
		}
		temp = temp->next;
	}
	
	if (file_list != NULL) {
		mx_printstr("\n");
	}

	if (file_list != NULL && dir_len > 0) {
		mx_printstr("\n");
	}
}
