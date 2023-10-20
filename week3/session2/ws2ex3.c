#include <stdio.h>

int str_len(char str[]){
    int count = 0;

    while(str[count] != '\0'){
        count ++;
    }
    return count;
}

int main (){
    char string[50];
    printf("Enter a string (no spaces): \n");
    scanf("%s", string);

    int length = str_len(string);

    printf("The string is %d characters long.\n", length);
    
    return 0;
}