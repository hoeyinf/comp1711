#include <stdio.h>

int main (){
    float a;
    float b = 3.641;
    float c;

    a = 2.897;
    c = a + b;

    printf("The sum of %f and %f is %.3f\n", a, b, c); //prints answer to 3 decimal places

    return 0;
}