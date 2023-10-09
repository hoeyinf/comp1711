#include <stdio.h>

int main (){
    int first, second, sum;
    printf("Enter first integer: ");
    scanf("%d", &first);

    printf("Enter second integer: ");
    scanf("%d", &second);

    sum = first + second;

    printf("%d + %d = %d\n", first, second, sum);

    return 0;
}