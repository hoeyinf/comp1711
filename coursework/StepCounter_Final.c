#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
int lines = 0, stepsLeast = 9999, stepsMost = -1, total = 0;
char choice, dateLeast[11], timeLeast[6], dateMost[11], timeMost[6];
double mean;
// Global variables for filename and FITNESS_DATA array
char filename[100], reader, line[100], date[11], time[6], steps[10];

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
    
    while (choice != 'Q'){ // repeats until Quit is selected
        // prints menu and prompts user for input
        printf("Menu Options:\n"
        "A: Specify the filename to be imported\n"
        "B: Display the total number of records in the file\n"
        "C: Find the date and time of the timeslot with the fewest steps\n"
        "D: Find the date and time of the timeslot with the largest number of steps\n"
        "E: Find the mean step count of all the records in the file\n"
        "F: Find the longest continuous period where the step count is above 500 steps\n"
        "Q: Quit\n"
        "Enter choice: ");
        // user menu input
        scanf(" %c", &choice);
        switch(choice){
            case 'A':;
                printf("Input filename: \n");
                scanf("%s", filename);
                // tries to open filename, error message and returns 1 if unable
                FILE *file = fopen(filename, "r");
                if (file == NULL) {
                    printf("Error: Could not find or open the file.\n");
                    return 1;
                }
                break;
            case 'B':
                rewind(file);
                // counts number of records (newlines) in file
                reader = getc(file);
                while (reader != EOF) {
                    if (reader == '\n'){    
                        lines++;
                    }
                    reader = getc(file);
                }
                printf("Total records: %d\n", lines);
                break;
            case 'C':
                rewind(file);
                while (fgets(line, 100, file) != NULL) {
                    tokeniseRecord(line, ",", date, time, steps);
                    if (atoi(steps) < stepsLeast){ // when least steps (so far) is encountered
                        // update relavant variables
                        stepsLeast = atoi(steps);
                        strcpy(dateLeast, date);
                        strcpy(timeLeast, time);
                    }
                }
                printf("Fewest steps: %s %s\n", dateLeast, timeLeast);
                break;
            case 'D':
                rewind(file);
                // same as C, but instead records for when most steps (so far) is encountered
                while (fgets(line, 100, file) != NULL) {
                    tokeniseRecord(line, ",", date, time, steps);
                    if (atoi(steps) > stepsMost){
                        stepsMost = atoi(steps);
                        strcpy(dateMost, date);
                        strcpy(timeMost, time);
                    }
                }
                printf("Largest steps: %s %s\n", dateMost, timeMost);
                break;
            case 'E':
                rewind(file);
                // summing all steps from each line in the file
                while (fgets(line, 100, file) != NULL) {
                    tokeniseRecord(line, ",", date, time, steps);
                    total += atof(steps);
                }
                // if B hasn't run yet, calculate number of lines
                if(lines == 0){
                    rewind(file);
                    reader = getc(file);
                    while (reader != EOF) {
                        if (reader == '\n'){    
                            lines++;
                        }
                    reader = getc(file);
                    }
                }
                // calculating mean (rounded), then output (to 0 decimal places)
                mean = roundf(total/lines);
                printf("Mean step count: %.0f\n", mean);
                break;
            case 'F':
                printf("Bye");
                break;
            case 'Q':
                fclose(file);
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }
}









