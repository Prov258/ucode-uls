#include "../inc/libmx.h"

char* mx_itoa(int number) {
    int numDigits = 1;
    int temp = number;
    while (temp / 10 != 0) {
        temp /= 10;
        numDigits++;
    }

    if (number < 0) {
        numDigits++; 
    }

    char* str = (char*)malloc(numDigits + 1);

    if (str == NULL) {
        return NULL;
    }

    int index = 0;
    if (number < 0) {
        str[index++] = '-';
        number = -number;
    }

    while(number!=0){
        str[index++] = '0'+(number%10);
        number/=10;
    }

    str[index] = '\0';

    int start = (str[0] == '-') ? 1 : 0;
    int end = index - 1;
    while (start < end) {
        char tempChar = str[start];
        str[start] = str[end];
        str[end] = tempChar;
        start++;
        end--;
    }

    return str;
}

