#include <uls.h>

void mx_print_permission(mode_t mode){
    mx_printchar((S_ISDIR(mode)) ? 'd' : '-');
    mx_printchar((S_IRUSR & mode) ? 'r' : '-');
    mx_printchar((S_IWUSR & mode) ? 'w' : '-');
    mx_printchar((S_IXUSR & mode) ? 'x' : '-');
    mx_printchar((S_IRGRP & mode) ? 'r' : '-');
    mx_printchar((S_IWGRP & mode) ? 'w' : '-');
    mx_printchar((S_IXGRP & mode) ? 'x' : '-');
    mx_printchar((S_IROTH & mode) ? 'r' : '-');
    mx_printchar((S_IWOTH & mode) ? 'w' : '-');
    mx_printchar((S_IXOTH & mode) ? 'x' : '-');
    mx_printstr(" ");
}

// void mx_print_permissions(t_list** dir_list, int dir_len){
//     for (int i = 0; i < dir_len; i++){
//         struct stat statRes;
//         t_list* current = dir_list[0];
//         while (current->next != NULL){
//             stat((char*)current->data, &statRes);
//             mode_t mode = statRes.st_mode;
//             char result[11];
//             result[0] = mx_check_permission_mode(mode);
//             result[1] = (S_IRUSR & mode) ? 'r' : '-';
//             result[2] = (S_IWUSR & mode) ? 'w' : '-';
//             result[3] = (S_IXUSR & mode) ? 'x' : '-';
//             result[4] = (S_IRGRP & mode) ? 'r' : '-';
//             result[5] = (S_IWGRP & mode) ? 'w' : '-';
//             result[6] = (S_IXGRP & mode) ? 'x' : '-';
//             result[7] = (S_IROTH & mode) ? 'r' : '-';
//             result[8] = (S_IWOTH & mode) ? 'w' : '-';
//             result[9] = (S_IXOTH & mode) ? 'x' : '-';
//             result[10] = '\0';
//             for (int i = 0; i < 10; i++){
//                 mx_printchar(result[i]);
//             }
//             mx_printstr("\n");
//             current = current->next;
//         }
//     }
    
    
// }
