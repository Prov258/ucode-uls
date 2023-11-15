#include "../inc/libmx.h"

char *mx_del_extra_spaces(const char *str){
    if(!str){
        return NULL;
    }
    char* temp = mx_strnew(mx_strlen(str));
    int tempIndex = 0;
    int origIndex = 0;
    while(str[origIndex] != '\0'){
        if(!mx_isspace(str[origIndex])){
            temp[tempIndex] = str[origIndex];
            tempIndex++;
        }
        if (!mx_isspace(str[origIndex]) && mx_isspace(str[origIndex+1])){
            temp[tempIndex] = ' ';
            tempIndex++;
        }
        origIndex++;
    }
    char *res = mx_strtrim(temp);
    mx_strdel(&temp);
    return res;
}

