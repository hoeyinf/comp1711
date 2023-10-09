#include <stdio.h>

int main (){
    int age;

    printf("Enter your age: ");
    scanf("%d", &age); //the ampersand means to store it at the address (variable)
    printf("Your age is %d\n", age);

    return 0;
}