#include <stdio.h>
#include <math.h> //needed to use M_PI for pi

int main (){
    float radius, area;

    printf("Enter circle's radius: \n");
    scanf("%f", &radius);
    area = M_PI * radius * radius;
    printf("The circle's area is %.2f\n", area);
}