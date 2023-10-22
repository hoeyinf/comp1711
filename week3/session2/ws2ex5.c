#include <stdio.h>

int str_len(const char* str){
    int count = 0;
    while(str[count] != '\0'){
        count ++;
    }
    return count;
}

#include <stdlib.h>
#include <string.h>


//FIGURE OUT WHAT THIS MEANS???
char *concatStrings(const char *str1, const char *str2) {
    char *ret = malloc((str_len(str1) + str_len(str2) + 1) * sizeof(char));
    char *p = ret;
    while (*str1 != '\0') {
        *p++ = *str1++;
    }
    while (*str2 != '\0') {
        *p++ = *str2++;
    }
    *p = '\0';
    return ret;
}

int main (){
    char str1[100], str2[100];
    printf("Enter first string: \n");
    scanf("%s", str1);
    printf("Enter second string: \n");
    scanf("%s", str2);

    printf("%s\n", concatStrings(str1, str2));

    return 0;
}