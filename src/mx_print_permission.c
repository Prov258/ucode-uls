#include "uls.h"

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

