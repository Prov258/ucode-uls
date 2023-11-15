#include "../inc/libmx.h"

void mx_pop_back(t_list **head){
    if(*head == NULL || head == NULL){
        return;
    }
    t_list *tmp = *head;    
    if(tmp->next == NULL){
        free(tmp);
        *head = NULL;   
        return;
    }
    while(tmp->next->next != NULL){
        tmp = tmp->next;
    }
    free(tmp->next);
    tmp->next = NULL;
}

