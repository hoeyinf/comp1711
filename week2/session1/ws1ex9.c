#include <stdio.h>

int main (){
    int days;
    double c = 16094799096, distance;
    printf("Enter number of days: \n");
    scanf("%d", &days);
    
    distance = c*days;
    printf("Light would have traveled %.0lf miles in %d days.\n", distance, days);

    return 0;
}