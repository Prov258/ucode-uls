#include <uls.h>

void mx_check_flag(char* flags){
    char* temp = "ACGRSTcfglmortux1";
    int temp_len = mx_strlen(temp);
    int i = 0;
    while(flags[i] != '\0'){
        bool check = false;
        for (int j = 0; j < temp_len; j++){
            if(flags[i] == temp[j]){
                check = true;
            }
        }
        if(!check){
            mx_printerr("uls: illegal option -- ");
            mx_printchar(flags[i]);
            mx_printstr("\n");
            mx_printerr("usage: uls [-ACGRSTcfglmortux1] [file ...]\n");
            exit(1);
        }
        i++;
    }
}
