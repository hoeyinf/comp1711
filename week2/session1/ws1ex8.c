#include <stdio.h>

int main (){
    int num, count, factorial = 1;
    printf("Enter an integer (1-9 only): \n");
    scanf("%d", &num);
    
    //setting count as num, the looping down and multiplying to get factorial
    count = num;
    for(count; count>1; count--){
        factorial *= count;
    }
    
    printf("The factorial of %d is %d.\n", num, factorial);

    return 0;
}