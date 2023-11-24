// FITNESS_DATA struct and tokeniseRecord function moved to header file
#include "FitnessDataStruct.h"

// Global variables for filename and FITNESS_DATA array
int records = 0;
char filename[100], choice, date[11], time[6], dateEnd[11], timeEnd[6];
FITNESS_DATA data[200];

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
        scanf("%c", &choice);
        while (getchar() != '\n');

        // switch case using user choice, choice is case-insensitive
        switch (choice)
        {
        case 'A':
        case 'a':
            // user inputs filename
            printf("Input filename: ");
            scanf("%s", filename);
            while (getchar() != '\n');
            // tries to open filename, prints error message and returns 1 if unable
            FILE *file = fopen(filename, "r");
            if (!file)
            {
                printf("Error: Could not find or open the file.\n");
                return 1;
            }
            // stores contents of file into the array, returns total number of records
            count_and_store(file, data, &records);
            fclose(file);
            break;
        case 'B':
        case 'b':
            printf("Total records: %d\n", records);
            break;
        case 'C':
        case 'c':
            leastSteps(data, records, date, time);
            printf("Fewest steps: %s %s\n", date, time);
            break;
        case 'D':
        case 'd':
            mostSteps(data, records, date, time);
            printf("Largest steps: %s %s\n", date, time);
            break;
        case 'E':
        case 'e':
            printf("Mean step count: %d\n", meanSteps(data, records));
            break;
        case 'F':
        case 'f':
            longestPeriod(data, records, date, time, dateEnd, timeEnd);
            printf("Longest period start: %s %s\nLongest period end: %s %s\n",
                   date, time, dateEnd, timeEnd);
            break;
        case 'Q':
        case 'q':
            return 0;
        // when something other than the valid cases above is entered
        default:
            printf("Invalid choice. Try again.\n");
            break;
        }
    }
}