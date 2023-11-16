#include <uls.h>

void mx_arg_error(char* file){
    mx_printerr("uls: ");
    mx_printerr(file);
    mx_printerr(": No such file or directory\n");
}
