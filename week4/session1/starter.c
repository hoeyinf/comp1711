#include <stdio.h>

int main (){
    float arr[10], total = 0, mean;
    for(int i=0;i<10;i++){
        printf("Enter number #%d: \n", i+1);
        scanf(" %f", &arr[i]);
        total += arr[i];
    }
    
    mean = total/10;
    printf("The mean of");
    for(int i=0;i<9;i++){
        printf(" %g,", arr[i]);
    }
    printf(" and %g is %g.\n", arr[9], mean);

    return 0;
}