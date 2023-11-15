#include "../inc/libmx.h"

void *mx_memchr(const void *s, int c, size_t n){
    const unsigned char *temp = (unsigned char *)s;
    for (size_t i = 0; i < n; i++){
        if(temp[i] == (unsigned char)c) { return (void *)(temp + i); }
    }
    return NULL;
}

