#include "../inc/libmx.h"

void mx_push_back(t_list **list, void *data){
    if (*list == NULL || list == NULL){
        *list = mx_create_node(data);
        return;
    }
    t_list *new = *list;
    while(new->next){
        new = new->next;
    }
    new->next = mx_create_node(data);
}

