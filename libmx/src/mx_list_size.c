#include "../inc/libmx.h"

int mx_list_size(t_list *list){
    if(list == NULL){
        return 0;
    }
    int len = 0;
    while(list){
        list = list->next;
        len++;
    }
    return len;
}

