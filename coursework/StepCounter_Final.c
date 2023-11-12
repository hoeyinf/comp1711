// Struct moved to header file
#include "FitnessDataStruct.h"

// Define any additional variables here
int lines = 0, i, stepsLeast = 9999, stepsMost = -1, mean, length = 0, lengthest = 0, end;
char choice, dateLeast[11], timeLeast[6], dateMost[11], timeMost[6], dateStart[11], timeStart[6], dateEnd[11], timeEnd[6];
double total = 0;
// Global variables for filename and FITNESS_DATA array
char filename[100], reader, line[100], date[11], time[6], steps[10];
FITNESS_DATA data[200];

// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps)
{
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);

    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL)
    {
        strcpy(date, token);
    }

    token = strtok(NULL, delimiter);
    if (token != NULL)
    {
        strcpy(time, token);
    }

    token = strtok(NULL, delimiter);
    if (token != NULL)
    {
        strcpy(steps, token);
    }

    // Free the duplicated string
    free(inputCopy);
}

// Complete the main function
int main()
{
    while (1) // will infinitely repeat (until Quit is selected, or invalid file name is entered)
    {
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
        // user input menu choice
        scanf(" %c", &choice);
        switch (choice)
        {
        case 'A':;
            printf("Input filename: ");
            scanf("%s", filename);
            // tries to open filename, prints error message and returns 1 if unable
            FILE *file = fopen(filename, "r");
            if (file == NULL)
            {
                printf("Error: Could not find or open the file.\n");
                return 1;
            }
            // reads and stores records from file into FITNESS_DATA array (data)
            // also counts number of records (lines)
            while (fgets(line, 100, file) != NULL)
            {
                tokeniseRecord(line, ",", date, time, steps);
                strcpy(data[lines].date, date);
                strcpy(data[lines].time, time);
                data[lines].steps = atoi(steps);
                lines++;
            }
            fclose(file);
            break;
        case 'B':
            // prints total records
            printf("Total records: %d\n", lines);
            break;
        case 'C':
            // loops through data
            for (i = 0; i < lines; i++)
            {
                if (data[i].steps < stepsLeast) // when least steps (so far) is encountered
                {
                    // updates relavant variables
                    stepsLeast = data[i].steps;
                    strcpy(dateLeast, data[i].date);
                    strcpy(timeLeast, data[i].time);
                }
            }
            // prints date and time of fewest steps
            printf("Fewest steps: %s %s\n", dateLeast, timeLeast);
            break;
        case 'D':
            // same as C, but for the most steps
            for (i = 0; i < lines; i++)
            {
                if (data[i].steps > stepsMost)
                {
                    stepsMost = data[i].steps;
                    strcpy(dateMost, data[i].date);
                    strcpy(timeMost, data[i].time);
                }
            }
            // prints date and time of largest steps
            printf("Largest steps: %s %s\n", dateMost, timeMost);
            break;
        case 'E':
            // sums all steps
            for (i = 0; i < lines; i++)
            {
                total += data[i].steps;
            }
            // calculates mean (rounded), then prints it
            mean = round(total / lines);
            printf("Mean step count: %d\n", mean);
            break;
        case 'F':
            // finds length of longest consecutive time period of 500+ steps, and its end date/time
            for (i = 0; i < lines; i++)
            {
                if (data[i].steps > 500)
                {
                    length++;
                    if (length > lengthest) // if current period (of 500+ steps) is greater than longest period so far
                    {
                        lengthest = length;
                        end = i; // stores the index of the end of the current longest period
                    }
                }
                else
                {
                    length = 0; // resets length when steps <=500 (since it's not consecutive anymore)
                }
            }
            // stores the start/end dates and times
            strcpy(dateStart, data[end - lengthest + 1].date);
            strcpy(timeStart, data[end - lengthest + 1].time);
            strcpy(dateEnd, data[end].date);
            strcpy(timeEnd, data[end].time);
            // prints start/end dates and times
            printf("Longest period start: %s %s\nLongest period end: %s %s\n",
                   dateStart, timeStart, dateEnd, timeEnd);
            break;
        case 'Q':
            return 0; // quit
        default: // when something other than the valid cases above is entered
            printf("Invalid choice. Try again.\n");
            break;
        }
    }
}