#include "../inc/libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little,
size_t little_len){
    if( big_len >= little_len && big_len > 0 && little_len > 0){
        unsigned char *bg_temp = (unsigned char *)big;
        unsigned char *ltl_temp = (unsigned char *)little;
        while(*bg_temp){
            if(!mx_memcmp(bg_temp, ltl_temp, little_len - 1)){
                return bg_temp;
            }
            bg_temp++;
        }
    }
    return NULL;
}

