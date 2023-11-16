#include <uls.h>

int main(int argc, char* argv[]) {
	int count_flags, count_args, dir_list_len;
	char* flags = mx_flag_definition(argv, argc, &count_args, &count_flags);
	char** file_arr = mx_arg_definition(argv, argc, count_args);
	t_list* file_list = NULL;
	t_list** dir_list = mx_filling_arr(file_arr, count_args, &file_list, &dir_list_len);
	// t_list** dir_list = (t_list**) malloc(sizeof(t_list*) * count_args);
	// int dir_list_len = 0;
	
	// t_list* file_list = NULL;

	// for (int i = 0; i < count_args; i++) {
	// 	DIR* dir = opendir(file_arr[i]);
	// 	struct dirent *test;
	// 	struct stat stat_temp;

	// 	stat(file_arr[i], &stat_temp);
	// 	if (!S_ISDIR(stat_temp.st_mode)) {
	// 		mx_push_back(&file_list, (void *) file_arr[i]);
	// 	} else {
	// 		dir_list[dir_list_len++] = mx_create_node((void *) file_arr[i]);
	// 		for (test = readdir(dir); test != NULL; test = readdir(dir)) {
	// 			if (mx_strcmp(test->d_name, ".") != 0 && mx_strcmp(test->d_name, "..") != 0) {
	// 				mx_push_back(&dir_list[dir_list_len - 1], (void *) test->d_name);
	// 			}
	// 		}
	// 	}
	// }

	mx_print_files(dir_list_len, file_list);
	mx_print_dir(dir_list, dir_list_len);

	mx_strdel(&flags);
	mx_del_strarr(&file_arr);
	return 0;
}

