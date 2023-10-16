#include <stdio.h>

int main (){
    
    float grade;

    printf("Enter student's grade: \n");
    scanf("%f", &grade);

    if(grade < 0 || grade > 100){
        printf("%g is not a valid grade.\n", grade);
    }else if(grade >= 70){
        printf("Student has earned a distinction.\n");
    }else if(grade >= 50){
        printf("Student has passed.\n");
    }else{
        printf("Student has failed.\n");
    }

    return 0;
}