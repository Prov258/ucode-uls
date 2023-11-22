#include "uls.h"

char* mx_flag_definition(char* argv[], int argc, int* count_args, int* count_flags){
    int temp_flags = 0;
    int block_with_flag = 0;
    int temp_args = 0;
    char buf[100];
    for (int i = 1; i < argc; i++){
        if(argv[i][0] != '-'){
            temp_args++;
        }
        else{
            block_with_flag++;
            int j = 1;
            while(mx_isalpha(argv[i][j]) && j <= mx_strlen(argv[i])){
                temp_flags++;
                j++;
            }
        }
    }
    *count_args = temp_args;
    *count_flags = temp_flags;
    char* result = malloc(temp_flags * sizeof(char));
    int temp = 0;
    for (int i = 0; i < block_with_flag; i++){
        for (int j = 1; argv[i + 1][j] != '\0'; j++){
            if (temp < temp_flags){
                buf[temp] = argv[i + 1][j];
                temp++;
            }
        }
    }
    buf[temp] = '\0';
    result = mx_strdup(buf);
    mx_check_flag(result);
    return result;
}

