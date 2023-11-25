#include "uls.h"

t_list** mx_filling_arr(char** file_arr, int count_args, t_list** file_list, int* dir_len, int* error){
    t_list** dir_list = (t_list**) malloc(sizeof(t_list*) * count_args);
	int dir_list_len = 0;
	
	t_list* temp_list = NULL;

	for (int i = 0; i < count_args; i++) {
		DIR* dir = opendir(file_arr[i]);
		struct dirent *test;
		struct stat stat_temp;

		if (stat(file_arr[i], &stat_temp) == -1) {
			mx_arg_error(file_arr[i]);
			*error = 1;
			continue;
		}

		if (dir == NULL && S_ISDIR(stat_temp.st_mode)) {
			mx_arg_error(file_arr[i]);
			*error = 1;
			continue;
		}

		if (!S_ISDIR(stat_temp.st_mode)) {
			mx_push_back(&temp_list, (void *) file_arr[i]);
		} else {
			dir_list[dir_list_len++] = mx_create_node((void *) file_arr[i]);
			for (test = readdir(dir); test != NULL; test = readdir(dir)) {
				if (test->d_name[0] != '.') {
					mx_push_back(&dir_list[dir_list_len - 1], (void *) test->d_name);
				}
			}
		}
	}

	for (int i = 0; i < dir_list_len; i++) {
		t_list* temp = mx_sort_list(dir_list[i]->next, mx_list_cmp);
		dir_list[i]->next = temp;
	}

	*dir_len = dir_list_len;
	*file_list = temp_list;
    return dir_list;
}

