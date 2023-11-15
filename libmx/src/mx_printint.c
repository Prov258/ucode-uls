#include "../inc/libmx.h"

void mx_printint(int n){
    if (n == 0){
        mx_printchar('0');
        return;
    }
    if (n == -2147483648) {
		write(1, "-2147483648", 11);
		return;
	}
    if (n < 0)
    {
        n*=-1;
        mx_printchar('-');
    }
    
    int start = n;
    int digits_num = 0;
    while (start != 0)
    {
        start/=10;
        digits_num++;
    }
    int array[digits_num];
    int counter_arr = 0;
    while (n!=0)
    {
        array[counter_arr] = n%10;
        n/=10;
        counter_arr++;
    }
    for (int i = counter_arr - 1; i >= 0; i--)
    {
        mx_printchar(array[i] + '0');
    }
}

