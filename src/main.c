#include <uls.h>

int main(int argc, char* argv[]) {
	int count_flags, count_args, dir_list_len;
	char* flags = mx_flag_definition(argv, argc, &count_args, &count_flags);
	char** file_arr = mx_arg_definition(argv, argc, &count_args);
	
	t_list* file_list = NULL;
	t_list** dir_list = mx_filling_arr(file_arr, count_args, &file_list, &dir_list_len);

	mx_print_files(dir_list_len, file_list);
	mx_print_dir(dir_list, dir_list_len, flags, count_flags);

	mx_strdel(&flags);
	mx_del_strarr(&file_arr);
	return 0;
}

