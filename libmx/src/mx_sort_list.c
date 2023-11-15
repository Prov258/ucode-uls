#include "../inc/libmx.h"

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)){
    if(lst == NULL || cmp == NULL){
        return lst;
    }
    int len = mx_list_size(lst);
    
    t_list *ths;
    for (int i = 0; i < len; i++){
        ths = lst;
        for (int j = 0; j < len - i - 1; j++){
            if(cmp(ths->data, ths->next->data)){
                void *tmp = ths->data;
                ths->data = ths->next->data;
                ths->next->data = tmp;
            }
            ths = ths->next;
        }
    }
    return lst;
}


