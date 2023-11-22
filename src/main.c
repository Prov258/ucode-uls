#include "uls.h"

int main(int argc, char* argv[]) {
	int count_flags, count_args, dir_list_len;
	char* flags = mx_flag_definition(argv, argc, &count_args, &count_flags);
	char** file_arr = mx_arg_definition(argv, argc, &count_args);
	
	t_list* file_list = NULL;
	t_list** dir_list = mx_filling_arr(file_arr, count_args, &file_list, &dir_list_len);

	struct winsize ws;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);

	if (count_flags == 0) {
		mx_print_files(file_list, ws);
	} else if (mx_is_flag(flags, count_flags, 'l')) {
		mx_ls_l(file_list, "./");
	}

	if (file_list != NULL && dir_list_len > 0) {
		mx_printstr("\n");
	}

	mx_print_dir(dir_list, dir_list_len, flags, count_flags, ws);

	mx_strdel(&flags);
	mx_del_strarr(&file_arr);
	return 0;
}

