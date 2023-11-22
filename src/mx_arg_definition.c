#include "uls.h"

char** mx_arg_definition(char* argv[], int argc, int* p_arguments_count){
    int arguments_count = *p_arguments_count;

    if(arguments_count == 0){
        char** result = (char **) malloc(sizeof(char *));
        result[0] = mx_strdup("./");
        *p_arguments_count = 1;

        return result;
    }

    char** result = (char **)malloc((arguments_count + 1) * sizeof(char *));
    int result_count = 0;
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
            result[result_count] = mx_strdup(buf);
            result_count++;
        }
    }
    mx_bubble_sort(result, arguments_count);
    return result;
}

