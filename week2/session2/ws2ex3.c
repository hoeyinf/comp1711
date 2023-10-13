#include <stdio.h>

int main (){
    
    int integers[5] = {2, 3, 1, 5, 4}, max = integers[0];
    
    for(int i=1; i<5; i++){
        if(max < integers[i]){
            max = integers[i];
        }
    }

    printf("Largest integer in the array is %d\n", max);

    return 0;
}