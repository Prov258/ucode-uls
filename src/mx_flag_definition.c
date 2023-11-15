#include <uls.h>

char* mx_flag_definition(char* argv[], int argc, int* countArgs, int* countFlags){
    int tempFlags = 0;
    int tempArgs = 0;
    char buf[100];
    for (int i = 1; i < argc; i++){
        if(argv[i][0] != '-'){
            tempArgs++;
        }
        else{
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
    for (int i = 1; i < tempFlags; i++){
        for (int j = 1; j < mx_strlen(argv[i]); j++){
            buf[temp] = argv[i][j];
            temp++;
        }
    }
    buf[temp] = '\0';
    result = mx_strdup(buf);
    return result;
}
