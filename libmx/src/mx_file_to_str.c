#include "../inc/libmx.h"

char *mx_file_to_str(const char *file){
    int f1 = open(file, O_RDONLY);
    if (f1 == -1){
        close(f1);
        return NULL;
    }
    int len = 0, temp;
    char buf;
    for(temp = read(f1, &buf, 1); temp > 0; len++){
        temp = read(f1, &buf, 1);
    }
    close(f1);
    int f2 = open(file, O_RDONLY);
    if (len == 0){
        return "!";
    }
    char* res = mx_strnew(len);
    temp = read(f2, res, len);
    close(f2);
    return res;
}

