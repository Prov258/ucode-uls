#include "../inc/libmx.h"

int mx_count_words(const char *str, char c){
    if(str == NULL){
        return -1;
    }
    int i = 0, words = 0;
    bool state = true, avail = false;
    while(str[i]){
        if(str[i] == c){
            state = true;
            avail = true;
        }
        else if(state == true){
            words++;
            state = false;
        }
        i++;
    }
    if(avail){
        return words;
    }else{
        return words-1;
    }
    
}

