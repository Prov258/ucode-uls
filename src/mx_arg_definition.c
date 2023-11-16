#include <uls.h>

char** mx_arg_definition(char* argv[], int argc, int argumentsCount){
    if(argumentsCount == 0){
        return NULL;
    }
    char** result = (char **)malloc((argumentsCount + 1) * sizeof(char *));
    int resultCount = 0;
    char buf[100];

    for (int i = 1; i < argc; i++){
        if(argv[i][0] == '-'){
            continue;
        }
        else{
            int j = 0;
            while(j < mx_strlen(argv[i])){
                buf[j] = argv[i][j];
                j++;
            }
            buf[j] = '\0';
            result[resultCount] = mx_strdup(buf);
            resultCount++;
        }
    }
    mx_bubble_sort(result, argumentsCount);
    return result;
}

