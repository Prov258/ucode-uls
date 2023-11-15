#include "../inc/libmx.h"

void *mx_realloc(void *ptr, size_t size){
    if(ptr == NULL && size > 0){
        return malloc(size);
    }

    size_t len = malloc_size(ptr);
    if(size <= len){
        size = len;
    }
    void *res;
    res = malloc(size);
    mx_memcpy(res, ptr, len);
    free(ptr);
    return res;
}

