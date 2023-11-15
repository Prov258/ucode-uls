#include "../inc/libmx.h"

char* mx_nbr_to_hex(unsigned long nbr) {
    int numDigits = 1;
    unsigned long temp = nbr;
    while (temp > 15) {
        temp /= 16;
        numDigits++;
    }

    char* hexString = (char*)malloc(numDigits + 1);

    if (hexString == NULL) {
        return NULL;
    }
    for (int i = numDigits - 1; i >= 0; i--) {
        int digit = nbr % 16;
        hexString[i] = (digit < 10) ? ('0' + digit) : ('a' + digit - 10);
        nbr /= 16;
    }
    hexString[numDigits] = '\0';

    return hexString;
}

