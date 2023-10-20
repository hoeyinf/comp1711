#include <stdio.h>

float circleArea (float radius){
    float area = 3.14 * radius * radius;
    return area;
}

int main (){
    float radius, area;
    printf("Enter the radius of the circle: \n");
    scanf("%f", &radius);

    area = circleArea(radius);

    printf("Area is %g\n", area);
    
    return 0;
}