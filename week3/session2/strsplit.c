#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

}

int main() {
    char record[21] = "2023-09-01,07:30,300";
    char dat[11];
    char tim[6];
    char ste[10];  // Large enough to hold a typical step count as a string

    int stepsint;
    
    tokeniseRecord(record, ",", dat, tim, ste);
    
    printf("Date: %s\n", dat);
    printf("Time: %s\n", tim);
    printf("Steps: %s\n", ste);

    // Convert the steps string to an integer
    stepsint = atoi(ste);
    printf("Steps as an integer: %d\n", stepsint);
    
    return 0;
}
