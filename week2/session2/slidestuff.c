#include <stdio.h>

int main (){
    int i = 0;
    for(i; i <= 20; i++){
        if(i % 2 == 1){
            printf("%d\n", i);
        }
    }
    printf("End activity 1\n");

    int a = 20;
    while(a >= 1){
        if(a % 2 == 0){
            printf("%d\n", a);
        }
        a -= 1;
    }
    printf("End activity 2\n");

    for(int x = 1; x <= 10; x++){
        printf("%d\n", x*x);
    }
    printf("End activity 3\n");

    return 0;
}