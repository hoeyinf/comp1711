#include <stdio.h>

int main (){
    int first, second, temp;
    printf("Enter the first integer: \n");
    scanf("%d", &first);
    printf("Enter the second integer: \n");
    scanf("%d", &second); 
    printf("first = %d, second = %d\n", first, second);   

    temp = first;
    first = second;
    second = temp;

    printf("first = %d, second = %d\n", first, second); 
    
    return 0;
}