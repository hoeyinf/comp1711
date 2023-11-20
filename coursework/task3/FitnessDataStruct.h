#ifndef FITNESS_DATA_STRUCT_H
#define FITNESS_DATA_STRUCT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define buffer 100

// FITNESS_DATA structure
typedef struct
{
    char date[11];
    char time[6];
    int steps;
} FITNESS_DATA;

void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, int *steps)
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
        *steps = atoi(token);
    }
    free(inputCopy);
}

// Checks each line for correct format, stores it into the array, and counts number of records
// @return True if file is in invalid format
bool validate_store_count(FILE *inputFile, FITNESS_DATA *dataArray, int *records)
{
    bool error = false;
    int countcomma, count = 0;
    char line[buffer];
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

        // if record has an empty field, or not exactly 3 fields, returns true for an error
        if (line[0] == ',' || strstr(line, ",,") != NULL ||
            line[strlen(line) - 2] == ',' || countcomma != 2)
        {
            error = true;
            return error;
        }

        tokeniseRecord(line, ",", dataArray[count].date, dataArray[count].time, &dataArray[count].steps);

        // if date or time has an incorrect length, return true for an error
        if (strlen(dataArray[count].date) != 10 || strlen(dataArray[count].time) != 5){
            error = true;
            return error;
        }
        count++;
    }
    // updates records with number of records in file
    *records = count;
    return error;
}

// sorts FITNESS_DATA array from highest to lowest number of steps, using a bubble sort
void sort_data(FITNESS_DATA *dataArray, int rows)
{
    bool sorted = false;
    int compareOne, compareTwo;
    char tempDate[11], tempTime[6];
    // loops until no swaps are made through the array (array is sorted)
    while (sorted == false)
    {
        sorted = true;
        for (int i = 0; i < rows - 1; i++)
        {
            compareOne = dataArray[i].steps;
            compareTwo = dataArray[i + 1].steps;
            // swaps values when next element is higher than current element
            if (compareTwo > compareOne)
            {
                // store dataArray[i] in temporary holding variables
                strcpy(tempDate, dataArray[i].date);
                strcpy(tempTime, dataArray[i].time);
                // replace dataArray[i] with dataArray[i+1]
                dataArray[i].steps = compareTwo;
                strcpy(dataArray[i].date, dataArray[i + 1].date);
                strcpy(dataArray[i].time, dataArray[i + 1].time);
                // replace dataArray[i+1] with dataArray[i] using temp variables
                dataArray[i + 1].steps = compareOne;
                strcpy(dataArray[i + 1].date, tempDate);
                strcpy(dataArray[i + 1].time, tempTime);
                sorted = false;
            }
        }
    }
}

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