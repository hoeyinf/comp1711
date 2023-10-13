#include <stdio.h>

int main (){
    int integers[5] = {1, 2, 3, 4, 5};
    int reverse[5], count = 0;
        for(int i=4; i>=0; i--){
        reverse[count] = integers[i];
        printf("%d\n", reverse[count]);
        count += 1;
    }

    for(int i=0; i<5; i++){
        printf("%d\n", reverse[i]);
    }

    return 0;
}