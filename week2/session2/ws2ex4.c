#include <stdio.h>

int main (){
    int integers[5] = {1, 2, 3, 4, 5}, rotate[5];

    for(int i=1; i<6; i++){
        rotate[i] = integers[i-1];
    }
    
    for(int i=0; i<6; i++){
        printf("%d\n", rotate[i]);
    }

    return 0;
}