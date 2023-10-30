#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here



// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
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

// Complete the main function
int main() {

    // opening CSV file, and checking it exists
    char *filename = "FitnessData_2023.csv";
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // finds the number of lines in the file
    int lines = 0;
    // reads file character by character, until end of file (EOF)
    char reader = getc(file);
    while (reader != EOF) {
        // increments lines counter when a new line is encountered
        if (reader == '\n'){    
            lines++;
        }
        // proceed to next character in file
        reader = getc(file);
    }
    
    // I based the above from:
    // https://stackoverflow.com/questions/10272896/reading-the-number-of-lines-in-a-file

    
    // printing number of records, using the counter
    printf("Number of records in file: %d\n", lines);

    FITNESS_DATA data[lines]; // creates an array the size of the file read

    // reset pointer to beginning of file
    rewind(file);

    // reading from file
    int buffer = 100, count = 0;
    char line[buffer], date[11], time[6], steps[10]; // the last three are used to store values from tokeniseRecord
    while (fgets(line, buffer, file) != NULL) {
        // breaks down each line in the file, using tokeniseRecord, into the separate values needed
        tokeniseRecord(line, ",", date, time, steps);
        // copies each value into its respective location in the named FITNESS_DATA typedef array (data)
        strcpy(data[count].date, date);
        strcpy(data[count].time, time);
        data[count].steps = atoi(steps);
        count++;
    }

    // printing the first three rows of the file
    for(int i=0; i<3; i++){
        printf("%s/%s/%d\n", data[i].date, data[i].time, data[i].steps);
    }

    fclose(file);
    return 0;
}