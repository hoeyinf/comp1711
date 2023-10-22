#include <stdio.h>

void reverseArray(int *arr, int length){
    int temp[length], i = length-1, j = 0;
    for(i; i>= 0; i--){
        temp[i] = arr[j];
        j++;
    }
    for(i=0; i<length; i++){
        arr[i] = temp[i];
    }
}

int main (){
    int arr[] = {5, 2, 2, 13, 6, 12, 24, 30042003}, i=0;
    
    int length = sizeof(arr)/sizeof(arr[0]);

    reverseArray(arr, length);

    for(i;i<length;i++){
        printf("%d\n", arr[i]);
    }
    return 0;
}