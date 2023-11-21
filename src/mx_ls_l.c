#include "uls.h"

void mx_ls_l(t_list* current) {
	int max_size = 0;
	t_list* parent = current;
	current = current->next;
	char* path = mx_strjoin(parent->data, "/");

	struct stat stat_res;
	long total_blocks = 0;
	t_list* temp = current;
	while (temp != NULL){
		char* temp_path = mx_strjoin(path, (char *) temp->data);
		stat(temp_path, &stat_res);
		temp = temp->next;
		total_blocks += stat_res.st_blocks;
		if (max_size < stat_res.st_size) {
			max_size = stat_res.st_size;
		}

		free(temp_path);
	}
	mx_printstr("total ");
	mx_printstr(mx_itoa(total_blocks));
	mx_printstr("\n");
        
	temp = current;
	while (temp != NULL){
		char* temp_path = mx_strjoin(path, (char *) temp->data);
		struct stat stat_res;
		struct passwd *pwd;
		struct group *grp;

		stat(temp_path, &stat_res);
		mx_print_permission(stat_res.st_mode);

		char* temp1 = mx_itoa(stat_res.st_nlink);
		mx_printstr(temp1);
		mx_printchar(' ');
		pwd = getpwuid(stat_res.st_uid);

		char* temp2 = NULL;
		if(pwd == NULL){
			temp2 = mx_itoa(stat_res.st_uid);
		} else {
			temp2 = mx_strdup(pwd->pw_name);
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
		mx_printstr(temp3);
		mx_printchar(' ');
		mx_printint(stat_res.st_size);
		mx_printchar(' ');

		char* time = ctime(&stat_res.st_mtime);
		time[mx_strlen(time) - 9] = '\0';
		time += 4;

		mx_printstr(time);

		mx_printchar(' ');
		mx_printstr(temp->data);
		mx_printchar('\n');

		temp = temp->next;

		free(temp1);
		free(temp2);
	}
}

