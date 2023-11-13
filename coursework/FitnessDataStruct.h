
#ifndef FITNESS_DATA_STRUCT_H
#define FITNESS_DATA_STRUCT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define buffer 100

// Define an appropriate struct
typedef struct
{
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Functions

// Helper function. Splits each file line into relevant data
void tokeniseRecord(const char *input, const char *delimiter,
					char *date, char *time, int *steps) // Changed 'char *steps' to 'int *steps'
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
		*steps = atoi(token); // changed 'strcpy(steps, token)' to '*steps = atoi(token)'
	}
}

// Reads and stores records from file into FITNESS_DATA array
// @return Total number of records
int count_and_store(FILE *inputFile, FITNESS_DATA *dataArray)
{
	int count = 0;
	char line[buffer];
	while (fgets(line, buffer, inputFile) != NULL)
	{
		// breaks up each line using ',' and stores the data into their respective variables in the array
		tokeniseRecord(line, ",", dataArray[count].date, dataArray[count].time, &dataArray[count].steps);
		count++;
	}
	return count;
}

// Finds the record in the array with the lowest steps
// @return Date and time of fewest steps
void stepsLeast(FITNESS_DATA *dataArray, int total, char *dateLeast, char *timeLeast)
{
	int minSteps = 9999;
	// loops through data
	for (int i = 0; i < total; i++)
	{
		if (dataArray[i].steps < minSteps) // when least steps (so far) is encountered
		{
			// updates relavant variables
			minSteps = dataArray[i].steps;
			strcpy(dateLeast, dataArray[i].date);
			strcpy(timeLeast, dataArray[i].time);
		}
	}
}

// Finds the record in the array with the most steps
// @return Date and time of most steps
void stepsMost(FITNESS_DATA *dataArray, int total, char *dateMost, char *timeMost)
{
	int maxSteps = -1;
	for (int i = 0; i < total; i++)
	{
		if (dataArray[i].steps > maxSteps)
		{
			maxSteps = dataArray[i].steps;
			strcpy(dateMost, dataArray[i].date);
			strcpy(timeMost, dataArray[i].time);
		}
	}
}

// Calculates mean steps taken
// @return Mean steps
int stepsMean(FITNESS_DATA *dataArray, int total)
{
	// if array is empty (user hasn't loaded file yet), prevents dividing by 0
	if (total == 0)
	{
		return 0;
	}
	// sums all steps
	int totalSteps = 0, mean = 0;
	for (int i = 0; i < total; i++)
	{
		totalSteps += dataArray[i].steps;
	}
	// calculates mean (rounded), returns it
	mean = round(totalSteps / total);
	return mean;
}

// Finds the longest consecutive period >500 steps, and the starting/ending dates and times
// @return Starting date and time, ending date and time
void longestPeriod(FITNESS_DATA *dataArray, int total, char *dateStart, char *timeStart, char *dateEnd, char *timeEnd)
{
	// if array is empty (user hasn't loaded file yet), prevents a Segmentation fault
	if (total == 0)
	{
		return;
	}
	int length = 0, lengthest = 0, end;
	// finds length of longest consecutive time period of 500+ steps, and its end date/time
	for (int i = 0; i < total; i++)
	{
		if (dataArray[i].steps > 500)
		{
			length++;
		}
		else
		{
			// if current period (of 500+ steps) is greater than longest period so far
			if (length > lengthest)
			{
				lengthest = length;
				end = i - 1; // stores the index of the end of the current longest period (previous index)
			}
			// resets length (since it's not consecutive anymore)
			length = 0;
		}
	}
	// stores the start/end dates and times
	strcpy(dateStart, dataArray[end - lengthest + 1].date);
	strcpy(timeStart, dataArray[end - lengthest + 1].time);
	strcpy(dateEnd, dataArray[end].date);
	strcpy(timeEnd, dataArray[end].time);
}

#endif // FITNESS_DATA_STRUCT_H