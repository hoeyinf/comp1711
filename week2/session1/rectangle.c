#include <stdio.h>

int main (){
    float length, width, area;

    printf("Enter length of rectangle: ");
    scanf("%f", &length);

    printf("Enter width of rectangle: ");
    scanf("%f", &width);

    area = length*width;
    
    printf("The area of the rectangle is %g x %g = %g\n", length, width, area);

    return 0;
}