#include <stdio.h>

int main (){
    int one[] = {1, 2, 3}, two[] = {10, 11, 12}, length;
    length = sizeof(one)/sizeof(int) + sizeof(two)/sizeof(int);
    int three[length];

    for(int i=0; i<length; i++){
        if(i < length){
            three[i] = one[i];
        }else{
            three[i] = two[i];
        }
         printf("%d\n", three[i]);
    }
    return 0;
}