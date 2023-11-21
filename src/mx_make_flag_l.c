#include "uls.h"

void mx_make_flag_l(t_list** dir_list, int dir_len){
    for (int i = 0; i < dir_len; i++) {
        struct stat statRes;
        long total_blocks = 0;
        t_list* current = dir_list[0];
        while (current->next != NULL){
            stat((char*)current->data, &statRes);
            current = current->next;
            total_blocks+= statRes.st_blocks;
        }
        mx_printstr(mx_itoa(total_blocks));
        mx_printstr("\n");
    }
    


    for (int i = 0; i < dir_len; i++){
        
        t_list* current = dir_list[0];
        while (current->next != NULL){
            struct stat statRes;
            struct passwd *pwd;
            struct group *grp;
            stat((char*)current->data, &statRes);
            mx_print_permission(statRes.st_mode);
            char* temp1 = NULL;
            temp1 = mx_itoa(statRes.st_nlink);
            mx_printstr(temp1);
            free(temp1);
            mx_printchar(' ');
            pwd = getpwuid(statRes.st_uid);
            char* temp2 = NULL;
            if(pwd == NULL){
                temp2 = mx_itoa(statRes.st_uid);
            } else {
                temp2 = mx_strdup(pwd->pw_name);
            }
            mx_printstr(temp2);
            free(temp2);
            mx_printchar(' ');
            grp = getgrgid(statRes.st_gid);
            char* temp3 = NULL;
            if(grp == NULL){
                temp3 = mx_itoa(statRes.st_gid);
            } else {
                temp3 = mx_strdup(grp->gr_name);
            }
            mx_printstr(temp3);
            mx_printchar(' ');
            mx_printint(statRes.st_size);
            mx_printchar(' ');
            mx_printstr(ctime(&statRes.st_mtime));
            mx_printstr("\n");
            current = current->next;
        }
    }
}
