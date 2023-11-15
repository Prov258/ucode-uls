#include "../inc/libmx.h"

char* mx_strdup(const char *s1){
    char *str = mx_strnew(mx_strlen(s1));
    if (str == NULL){
        return NULL;
    }
    mx_strcpy(str, s1);
    return str;
}

