#include "../inc/libmx.h"

void mx_push_front(t_list **list, void *data){
    if (*list == NULL || list == NULL){
        *list = mx_create_node(data);
        return;
    }
    t_list *new = mx_create_node(data);
    new->data = data;
    new->next = *list;
    *list = new;
}

