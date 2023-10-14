#include <stdio.h>

int main (){
    char Hello[] = "Hello";
    int length = 0;

    //find length of the string
    while(Hello[length] != '\0'){
        length ++;
    }
    // range must start from length-1 since last position is just '/0'
    for(int i = length-1; i>=0; i--){
        printf("%c", Hello[i]);
    }
    printf("%d\n", Hello[5]);

    return 0;
}