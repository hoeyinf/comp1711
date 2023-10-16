#include <stdio.h>

int main (){
    float num;
    while(num != -1){
        printf("Enter a number between 0 and 100. Enter -1 to end the program.\n");
        scanf("%f", &num);

        if(num < -1 || num > 100){
            printf("Invalid input. ");
        }else if(num == -1){
            printf("Program ended.\n");
        }else{
            printf("You have entered %g! Amazing.\n", num);
        }
    }
    return 0;
}