#include <uls.h>

char* mx_flag_definition(char* argv[], int argc, int* countArgs, int* countFlags){
    int tempFlags = 0;
    int block_with_flag = 0;
    int tempArgs = 0;
    char buf[100];
    for (int i = 1; i < argc; i++){
        if(argv[i][0] != '-'){
            tempArgs++;
        }
        else{
            block_with_flag++;
            int j = 1;
            while(mx_isalpha(argv[i][j]) && j <= mx_strlen(argv[i])){
                tempFlags++;
                j++;
            }
        }
    }
    *countArgs = tempArgs;
    *countFlags = tempFlags;
    char* result = malloc(tempFlags * sizeof(char));
    int temp = 0;
    for (int i = 0; i < block_with_flag; i++){
        for (int j = 1; argv[i + 1][j] != '\0'; j++){
            if (temp < tempFlags){
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
