#include <stdio.h>

int main (){
    float temperature;

    printf("Enter the temperature in Celsius: \n");
    scanf("%f", &temperature);

    while(temperature < -10 || temperature > 40){
        printf("%g is not a valid temperature. Please enter a new temperature (in Celsius): \n", temperature);
        scanf("%f", &temperature);
    }
    
    printf("%g is a valid temperature.\n", temperature);

    return 0;
}