#ifndef FITNESS_DATA_STRUCT_H
#define FITNESS_DATA_STRUCT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define buffer 100

// FITNESS_DATA structure
typedef struct
{
    char date[11];
    char time[6];
    int steps;
} FITNESS_DATA;

void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps)
{
    char *inputCopy = strdup(input);
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
    free(inputCopy);
}

// checks if file is in the correct format
int validate_file(FILE *inputFile)
{
    int error = 0, countcomma, isint;
    char line[buffer], date[11], time[6], steps[10];
    while (fgets(line, buffer, inputFile) != NULL)
    {
        // counts number of ',' in line
        // should only have 2 ',' for three fields
        countcomma = 0;
        for (int i = 0; i < strlen(line) - 1; i++)
        {
            if (line[i] == ',')
            {
                countcomma++;
            }
        }

        tokeniseRecord(line, ",", date, time, steps);

        // checks that steps is an integer
        // loops through its string, converts each char using atoi()
        // if the char's atoi value is 0 (but not actually '0'), then it's not an int
        isint = 1;
        for (int i = 0; i < strlen(steps)-2; i++){
            if (atoi(&steps[i]) == 0 && steps[i] != '0'){
                isint = 0;
                break;
            }
        }

        // checks: if there are any empty fields
        // if there are too many/little fields
        // if date and time are correct length
        // if steps is an integer
        if (line[0] == ',' ||
            strstr(line, ",,") != NULL ||
            line[strlen(line) - 2] == ',' ||
            countcomma != 2 ||
            strlen(date) != 10 ||
            strlen(time) != 5 ||
            isint == 0)
        {
            error = 1;
            break;
        }
    }
    return error;
}

// Reads and stores records from file into FITNESS_DATA array, counts number of records
void count_and_store(FILE *inputFile, FITNESS_DATA *dataArray, int *records)
{
    int count = 0;
    char line[buffer], steps[10];
    rewind(inputFile);
    while (fgets(line, buffer, inputFile) != NULL)
    {

        tokeniseRecord(line, ",", dataArray[count].date, dataArray[count].time, steps);
        dataArray[count].steps = atoi(steps);
        count++;
    }
    // updates records with number of records in file
    *records = count;
}

// sorts FITNESS_DATA array from highest to lowest number of steps, using a bubble sort
void sort_data(FITNESS_DATA *dataArray, int rows)
{
    int sorted = 0, compareOne, compareTwo;
    FITNESS_DATA temp;
    // loops until no swaps are made through the array (array is sorted)
    while (sorted == 0)
    {
        sorted = 1;
        for (int i = 0; i < rows - 1; i++)
        {
            compareOne = dataArray[i].steps;
            compareTwo = dataArray[i + 1].steps;
            // swaps values when next element is higher than current element
            if (compareTwo > compareOne)
            {
                // store dataArray[i] in temporary holding variable
                temp = dataArray[i];
                // replace dataArray[i] with dataArray[i+1]
                dataArray[i] = dataArray[i+1];
                // replace dataArray[i+1] with dataArray[i] using temp variable
                dataArray[i+1] = temp;
                sorted = 0;
            }
        }
    }
}

// outputs contents of array as a tsv file
void output_tsv(char *filename, FITNESS_DATA *dataArray, int rows)
{
    // filename changed to have .tsv at the end of it
    strcat(filename, ".tsv");
    // creates file, writes contents of sorted array into it (tsv format)
    FILE *filenew = fopen(filename, "w");
    for (int i = 0; i < rows; i++)
    {
        fprintf(filenew, "%s\t%s\t%d\n", dataArray[i].date, dataArray[i].time, dataArray[i].steps);
    }
    fclose(filenew);
    printf("Data sorted and written to %s\n", filename);
}

#endif