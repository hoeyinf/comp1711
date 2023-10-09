#include <stdio.h>

int main (){
    //defines name as char with max 15 length
    char name[15];
    printf("Please enter your name: ");

    //reads input as a string, stores in a variable
    scanf("%s", name);

    //printing name
    printf("Your name is %s\n", name);

    return 0;
}