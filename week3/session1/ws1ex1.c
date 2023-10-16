#include <stdio.h>

int main (){
    float num;

    printf("Enter a number: \n");
    scanf("%f", &num);

    if(num > 0){
        printf("%g is a positive number.\n", num);
    }else if(num == 0){
        printf("%g is zero.\n", num);
    }else{
        printf("%g is a negative number.\n", num);
    } 
    return 0;
}