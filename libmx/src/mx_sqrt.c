#include "../inc/libmx.h"

int mx_sqrt(int x){
    if (x > 0){
        for (int i = 0; i < x; i++)
        {
            if (i*i == x)
            {
                return i;
            }
        }
        return 0;
    }
    else{
        return 0;
    } 
}

