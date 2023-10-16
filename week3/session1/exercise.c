#include <stdio.h>

int main (){
    int mark;
    printf("Enter the mark: \n");
    scanf("%d", &mark);

    if(mark < 0 || mark > 100){
        printf("%d is not a valid mark.\n", mark);
    }else if(mark >= 70){
        printf("%d is a first.\n", mark);
    }else if( mark >= 60){
        printf("%d is a 2:1.\n", mark);
    }else if(mark < 40){
        printf("%d is a fail.\n", mark);
    }else{
        printf("%d is a pass.\n", mark);
    }
    
    return 0;
}