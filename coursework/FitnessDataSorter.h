#ifndef FITNESS_DATA_SORTER_H
#define FITNESS_DATA_SORTER_H

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

// Helper function
void tokeniseRecord(const char *input, const char *delimiter,
					char *date, char *time, int *steps)
{
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
		*steps = atoi(token);
	}
	free(inputCopy);
}

// Reads and stores records from file into FITNESS_DATA array
// @return Total number of records
int count_and_store(FILE *inputFile, FITNESS_DATA *dataArray)
{
	int count = 0;
	char line[buffer];
	while (fgets(line, buffer, inputFile) != NULL)
	{
		tokeniseRecord(line, ",", dataArray[count].date, dataArray[count].time, &dataArray[count].steps);
		count++;
	}
	return count;
}

// sorts FITNESS_DATA array from highest to lowest number of steps, using a bubble sort
void sort_data(FITNESS_DATA *dataArray, int total)
{
	bool sorted = false;
	int compareOne, compareTwo;
	char tempDate[11], tempTime[6];
	// loops until no swaps are made through the array (array is sorted)
	while (sorted == false)
	{
		sorted = true;
		for (int i = 0; i < total - 1; i++)
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
				// replace dataArray[i+1] with dataArray[i]
				dataArray[i + 1].steps = compareOne;
				strcpy(dataArray[i + 1].date, tempDate);
				strcpy(dataArray[i + 1].time, tempTime);
				sorted = false;
			}
		}
	}
}

#endif