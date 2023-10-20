#include <stdio.h>
#include <string.h>


void concatStrings(char str1, char str2){
    return str1;
}

int main (){
    char string1[50], string2[50], concat;
    printf("Enter the first string: \n");
    scanf("%s", string1);
    printf("Enter the second string: \n");
    scanf("%s", string2);

    concat = concatStrings(string1, string2);
    printf("%s", concat);
    return 0;
}