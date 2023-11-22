#include "uls.h"

void mx_check_attribute(bool check, char* path){
	ssize_t check_attr = listxattr(path, NULL, 0);
	if(check_attr > 0){
		mx_printchar('@');
	} else {
		mx_printchar(' ');
	}
	if (check){
		mx_printchar(' ');
	}
}

void mx_ls_l(t_list* current, char* path) {
	int max_size = 0;
	int max_len_size = 0;
	int max_len_link = 0;
	int max_len_uid = 0;
	int max_len_grid = 0;
	bool check_space = false;

	struct stat stat_res;
	struct passwd *pwd;
	struct group *grp;

	long total_blocks = 0;
	t_list* temp = current;
	while (temp != NULL){
		char* temp_path = mx_strjoin(path, (char *) temp->data);
		stat(temp_path, &stat_res);

		ssize_t check_attr = listxattr(temp_path, NULL, 0);
		if(check_attr > 0){
			check_space = true;
		}

		char* temp_size = mx_itoa(stat_res.st_size);
		if(max_len_size < mx_strlen(temp_size)){
			max_len_size = mx_strlen(temp_size);
		}
		
		char* temp_link = mx_itoa(stat_res.st_nlink);
		if(max_len_link < mx_strlen(temp_link)){
			max_len_link = mx_strlen(temp_link);
		}
		
		pwd = getpwuid(stat_res.st_uid);
		if(pwd){
			if(max_len_uid < mx_strlen(pwd->pw_name)){
				max_len_uid = mx_strlen(pwd->pw_name);
			}
		} else {
			char* temp_uid = mx_itoa(stat_res.st_uid);
			if(max_len_uid < mx_strlen(temp_uid)){
				max_len_uid = mx_strlen(temp_uid);
			}
			free(temp_uid);
		}

		grp = getgrgid(stat_res.st_gid);
		if(grp){
			if(max_len_grid < mx_strlen(grp->gr_name)){
				max_len_grid = mx_strlen(grp->gr_name);
			}
		} else {
			char* temp_grid = mx_itoa(stat_res.st_gid);
			if(max_len_grid < mx_strlen(temp_grid)){
				max_len_grid = mx_strlen(temp_grid);
			}
			free(temp_grid);
		}

		temp = temp->next;
		total_blocks += stat_res.st_blocks;
		if (max_size < stat_res.st_size) {
			max_size = stat_res.st_size;
		}

		free(temp_size);
		free(temp_link);
		free(temp_path);
	}
	mx_printstr("total ");
	mx_printstr(mx_itoa(total_blocks));
	mx_printstr("\n");
        
	temp = current;
	while (temp != NULL){
		char* temp_path = mx_strjoin(path, (char *) temp->data);
		
		stat(temp_path, &stat_res);
		mx_print_permission(stat_res.st_mode);
		
		mx_check_attribute(check_space, temp_path);

		char* temp1 = mx_itoa(stat_res.st_nlink);
		for (int i = 0; i < max_len_link - mx_strlen(temp1); i++) {
			mx_printchar(' ');
		}
		mx_printstr(temp1);
		mx_printchar(' ');

		pwd = getpwuid(stat_res.st_uid);
		char* temp2 = NULL;
		if(pwd == NULL){
			temp2 = mx_itoa(stat_res.st_uid);
		} else {
			temp2 = mx_strdup(pwd->pw_name);
		}
		for (int i = 0; i < max_len_uid - mx_strlen(temp2); i++){
			mx_printchar(' ');
		}
		mx_printstr(temp2);
		mx_printchar(' ');

		grp = getgrgid(stat_res.st_gid);
		char* temp3 = NULL;
		if(grp == NULL){
			temp3 = mx_itoa(stat_res.st_gid);
		} else {
			temp3 = mx_strdup(grp->gr_name);
		}
		for (int i = 0; i < max_len_grid - mx_strlen(temp3); i++){
			mx_printchar(' ');
		}
		mx_printstr(temp3);
		mx_printchar(' ');

		char* temp4 = mx_itoa(stat_res.st_size);
		for (int i = 0; i < max_len_size - mx_strlen(temp4); i++){
			mx_printchar(' ');
		}
		mx_printstr(temp4);
		mx_printchar(' ');

		char* time = ctime(&stat_res.st_mtime);
		time[mx_strlen(time) - 9] = '\0';
		time += 4;

		mx_printstr(time);

		mx_printchar(' ');
		mx_printstr(temp->data);
		mx_printchar('\n');

		temp = temp->next;

		free(temp_path);
		free(temp1);
		free(temp2);
		free(temp3);
		free(temp4);
	}
}

