#include <uls.h>

int main(int argc, char* argv[]) {
	char** arr = (char**) malloc(sizeof(char*) * (argc - 1));
	int arr_len = argc - 1;
	for (int i = 1; i < argc; i++) {
		arr[i - 1] = mx_strdup(argv[i]);
	}

	mx_bubble_sort(arr, arr_len);

	t_list** dir_list = (t_list**) malloc(sizeof(t_list*) * arr_len);
	int dir_list_len = 0;

	t_list* file_list = NULL;

	for (int i = 0; i < arr_len; i++) {
		DIR* dir = opendir(arr[i]);
		struct dirent *test;
		struct stat stat_temp;

		stat(arr[i], &stat_temp);
		if (!S_ISDIR(stat_temp.st_mode)) {
			mx_push_back(&file_list, (void *) arr[i]);
		} else {
			dir_list[dir_list_len++] = mx_create_node((void *) arr[i]);
			for (test = readdir(dir); test != NULL; test = readdir(dir)) {
				if (mx_strcmp(test->d_name, ".") != 0 && mx_strcmp(test->d_name, "..") != 0) {
					mx_push_back(&dir_list[dir_list_len - 1], (void *) test->d_name);
				}
			}
		}
	}

	// print files
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

	if (file_list != NULL && dir_list_len > 0) {
		mx_printstr("\n");
	}

	// print dir

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
	
	return 0;
}

