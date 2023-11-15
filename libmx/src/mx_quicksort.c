#include "../inc/libmx.h"

int mx_quicksort(char **arr, int left, int right) {
    if(!arr){
        return -1;
    }
    if (left >= right){
        return 0;
    }

    int i = left;
    int j = right;
    int swapCount = 0;
    char* pivot = arr[(left + right)/2];
    
    while (1){
        while(mx_strlen(arr[i]) < mx_strlen(pivot)){
            i++;
        }
        while(mx_strlen(arr[j]) > mx_strlen(pivot)){
            j--;
        }
        if (i >= j){
            break;
        }
        if (mx_strlen(arr[i]) != mx_strlen(arr[j])){
            swapCount++;
            char* temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        i++;
        j--;
    }
    swapCount+=mx_quicksort(arr, left, j);
    swapCount+=mx_quicksort(arr, j+1, right);

    return swapCount;
}

