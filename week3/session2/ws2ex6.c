#include <stdio.h>

float answer(float a, float b, char *symb){
    float ans;
    switch(*symb){
        case '+': 
            ans = a + b;
            break;
        case '-': 
            ans = a - b;
            break;
        case '/':
            ans = a/b;
            break;
        case '*':
            ans = a*b;
            break;
        default:
            break;
    }
    return ans; 
}

int main (){
    float num1, num2, ans;
    char *opr;
    printf("Enter the first number: \n");
    scanf("%f", &num1);
    printf("Enter the second number: \n");
    scanf("%f", &num2);
    printf("Enter the operator: \n");
    scanf(" %c", opr);

    ans = answer(num1, num2, opr);
    printf("%g %c %g = %g\n", num1, *opr, num2, ans);
    
    return 0;
}