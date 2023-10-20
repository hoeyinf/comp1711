#include <stdio.h>

float volumeSphere(float r){
    float rCubed, v;
    rCubed = r*r*r;
    v = 3.14*rCubed*4/3;
    return v;
}

int main (){
    float radius, volume;
    printf("Enter the radius of the sphere: \n");
    scanf("%f", &radius);

    volume = volumeSphere(radius);

    printf("The volume of the sphere is %g.\n", volume);

    return 0;
}