#ifndef FITNESS_DATA_STRUCT_H
#define FITNESS_DATA_STRUCT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define buffer 100

// FITNESS_DATA struct
typedef struct
{
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Helper function. Splits each file line into relevant data
void tokeniseRecord(const char *input, const char *delimiter,
					char *date, char *time, int *steps) // Changed 'char *steps' to 'int *steps'
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
		*steps = atoi(token); // changed 'strcpy(steps, token)' to '*steps = atoi(token)'
	}
	free(inputCopy);
}

// Reads and stores records from file into FITNESS_DATA array, counts number of records
void count_and_store(FILE *inputFile, FITNESS_DATA *dataArray, int *records)
{
	int count = 0;
	char line[buffer];
	while (fgets(line, buffer, inputFile) != NULL)
	{
		// breaks up each line using ',' and stores the data into their respective variables in the array
		tokeniseRecord(line, ",", dataArray[count].date, dataArray[count].time, &dataArray[count].steps);
		count++;
	}
	*records = count;
}

// Finds the record in the array with the lowest steps, retrieves its date and time
void leastSteps(FITNESS_DATA *dataArray, int rows, char *dateLeast, char *timeLeast)
{
	int min = 9999;
	// loops through data
	for (int i = 0; i < rows; i++)
	{
		if (dataArray[i].steps < min) // when least steps (so far) is encountered
		{
			// updates relevant variables
			min = dataArray[i].steps;
			strcpy(dateLeast, dataArray[i].date);
			strcpy(timeLeast, dataArray[i].time);
		}
	}
}

// Finds the record in the array with the most steps, retrieves its date and time
void mostSteps(FITNESS_DATA *dataArray, int rows, char *dateMost, char *timeMost)
{
	int max = -1;
	for (int i = 0; i < rows; i++)
	{
		if (dataArray[i].steps > max) // when most steps (so far) is encountered
		{
			// updates relevant variables
			max = dataArray[i].steps;
			strcpy(dateMost, dataArray[i].date);
			strcpy(timeMost, dataArray[i].time);
		}
	}
}

// Calculates mean steps taken
// @return Mean steps, rounded to the nearest integer
int meanSteps(FITNESS_DATA *dataArray, int rows)
{
	int mean;
	double total, unrounded;
	// prevents dividing by 0 when calculating mean, if user hasn't loaded a valid file yet
	if (rows != 0)
	{
		// sums all steps
		total = 0;
		for (int i = 0; i < rows; i++)
		{
			total += dataArray[i].steps;
		}

		// calculates mean (rounded), returns it
		unrounded = total / rows;
		mean = unrounded;
		if (unrounded - mean >= 0.5)
		{
			mean++;
		}
	}
	else
	// if rows == 0
	{
		mean = 0;
	}
	return mean;
}

// Finds the longest consecutive period >500 steps, and the starting/ending dates and times
void longestPeriod(FITNESS_DATA *dataArray, int rows, char *dateStart, char *timeStart, char *dateEnd, char *timeEnd)
{
	// if array is empty (user hasn't loaded file yet), prevents a segmentation fault
	if (rows != 0)
	{
		int length = 0, lengthest = 0, end;

		// finds length of longest consecutive time period of 500+ steps, and its end date/time
		for (int i = 0; i < rows; i++)
		{
			if (dataArray[i].steps > 500)
			{
				length++;
				// if current period (of 500+ steps) is greater than longest period so far
				// use a nested if, so it will update if longest period ends on last entry
				if (length > lengthest)
				{
					lengthest = length;
					// stores the index of the end of the current longest period
					end = i;
				}
			}
			else // when steps <= 500
			{
				// resets length since it's not consecutive anymore
				length = 0;
			}
		}
		// if there is a period with >500 steps
		if (lengthest != 0)
		{
			// stores the start/end dates and times
			strcpy(dateStart, dataArray[end - lengthest + 1].date);
			strcpy(timeStart, dataArray[end - lengthest + 1].time);
			strcpy(dateEnd, dataArray[end].date);
			strcpy(timeEnd, dataArray[end].time);
		}
	}
}

#endif // FITNESS_DATA_STRUCT_H