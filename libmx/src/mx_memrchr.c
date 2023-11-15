#include "../inc/libmx.h"

void *mx_memrchr(const void *s, int c, size_t n){
    const unsigned char *temp = (unsigned char *)s;
    for (size_t i = n - 1; i >= 0; i--){
        if(temp[i] == (unsigned char)c) { return (void *)(temp + i); }
    }
    return NULL;
}

