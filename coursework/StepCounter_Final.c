// FITNESS_DATA struct and tokeniseRecord function moved to header file
#include "FitnessDataStruct.h"

// Define any additional variables here
int total = 0;
char choice, date[11], time[6], dateEnd[11], timeEnd[6];
// Global variables for filename and FITNESS_DATA array
char filename[100];
FITNESS_DATA data[200];

// Complete the main function
int main()
{
    while (1) // will infinitely loop (until Quit is selected, or invalid file name is entered)
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
        // user inputs choice
        // space needed before %c, or it reads \n from entering input, instead of the actual input
        scanf(" %c", &choice);
        // switch case using user choice, choice is case-insensitive
        switch (choice)
        {
        case 'A':
        case 'a':
            printf("Input filename: ");
            scanf("%s", filename);
            // tries to open filename, prints error message and returns 1 if unable
            FILE *file = fopen(filename, "r");
            if (!file)
            {
                printf("Error: Could not find or open the file.\n");
                return 1;
            }
            // stores contents of file into the array, returns total number of records
            total = count_and_store(file, data);
            fclose(file);
            break;
        case 'B':
        case 'b':
            // prints total records
            printf("Total records: %d\n", total);
            break;
        case 'C':
        case 'c':
            // finds record with fewest steps, returns its date and time
            stepsLeast(data, total, date, time);
            // prints date and time
            printf("Fewest steps: %s %s\n", date, time);
            break;
        case 'D':
        case 'd':
            // finds record with most steps, returns its date and time
            stepsMost(data, total, date, time);
            // prints date and time
            printf("Largest steps: %s %s\n", date, time);
            break;
        case 'E':
        case 'e':
            // stepsMean() finds the mean steps of the array
            printf("Mean step count: %d\n", stepsMean(data, total));
            break;
        case 'F':
        case 'f':
            // finds longest consecutive period of >500 steps, returns start/end dates and times
            longestPeriod(data, total, date, time, dateEnd, timeEnd);
            // prints start/end dates and times
            printf("Longest period start: %s %s\nLongest period end: %s %s\n",
                   date, time, dateEnd, timeEnd);
            break;
        case 'Q':
        case 'q':
            // quit
            return 0;
        default: // when something other than the valid cases above is entered
            printf("Invalid choice. Try again.\n");
            break;
        }
    }
}