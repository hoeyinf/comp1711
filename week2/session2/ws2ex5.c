#include <stdio.h>

int main (){
    int integers[] = {2, 3, 1, 4, 1, 3}, length;
    
    length = sizeof(integers) / sizeof(int); //finds length of array using sizeof()

    for(int i=0; i<length; i++){
        for(int j=0; j<length; j++){
            if(i != j && integers[i] == integers[j]){
                printf("There are duplicate %ds!\n", integers[i]);
            }
        }
    }
}