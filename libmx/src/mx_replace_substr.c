#include "../inc/libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    if(!str || !sub || !replace) {
        return NULL;
    }

    int len = mx_strlen(str) - (mx_count_substr(str, sub) * mx_strlen(sub)) + (mx_strlen(replace) * mx_count_substr(str, sub));

    char *temp = mx_strdup(str);
    char *result = mx_strnew(len);

    int i = 0;
    while(*temp) {
        if(!mx_strncmp(temp, sub, mx_strlen(sub))) {
            mx_strcat(result, replace);
            i += mx_strlen(replace);
            temp += mx_strlen(sub);
        }
        else {
            result[i++] = *temp++;
        }
    }
    result[len] = '\0';

    return result;
}

