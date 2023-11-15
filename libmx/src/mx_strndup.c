#include "../inc/libmx.h"

char *mx_strndup(const char *s1, size_t n){
    size_t len = mx_strlen(s1);
    if (n < len) {
        len = n;
    }
    char *str = mx_strnew(len);
    if(str == NULL){
        return NULL;
    }
    mx_strncpy(str, s1, len);
    return str;
}

