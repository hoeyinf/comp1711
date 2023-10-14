#include <stdio.h>

int main (){
    double principal, rate, simpleInterest;
    int time;
    printf("Enter the principal: \n");
    scanf("%lf", &principal);
    printf("Enter the per annum interest rate: \n");
    scanf("%lf", &rate);
    rate /= 100;
    printf("Enter the number of years: \n");
    scanf("%d", &time);

    simpleInterest = principal*rate*time;
    printf("Simple interest is %.2lf.\n", simpleInterest);

    return 0;
}