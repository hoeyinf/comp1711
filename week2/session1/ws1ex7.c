#include <stdio.h>

int main (){
    float fahrenheit, celsius;
    printf("Enter the temperature in Fahrenheit: \n");
    scanf("%f", &fahrenheit);
    
    celsius = (fahrenheit - 32)*5/9;

    printf("%.1f degrees Fahrenheit is %.1f degrees Celsius.\n", fahrenheit, celsius);
    
    return 0;
}