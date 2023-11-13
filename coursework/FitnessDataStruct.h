
#ifndef FITNESS_DATA_STRUCT_H
#define FITNESS_DATA_STRUCT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Helper function prototypes
// changed 'char *steps' to 'int *steps'
void tokeniseRecord(const char *input, const char *delimiter, char *date, char *time, int *steps);

#endif // FITNESS_DATA_STRUCT_H
