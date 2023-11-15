#include "../inc/libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n){
    const unsigned char *s1_temp = s1;
    const unsigned char *s2_temp = s2;
    for(size_t i = 0; s1_temp[i] != '\0' && s2_temp[i] != '\0' && i < n; i++){
        if(s1_temp[i] != s2_temp[i]){
            return s1_temp[i] - s2_temp[i];
        }
    }
    return 0;
}

