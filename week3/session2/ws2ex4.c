#include <stdio.h>

int isPrime(int num){
    int prime = 1, count = 2;
    while(count <= num/2){
        if(num % count == 0){
            prime = 0;
            break;
        }else{
            count++;
        }
    }
    return prime;
}

int main (){
    int input, prime;
    printf("Enter an integer: \n");
    scanf("%d", &input);

    prime = isPrime(input);

    printf("%d is ", input);
    if(prime == 1){
        printf("prime.\n");
    }else{
        printf("not prime.\n");
    }

    return 0;
}