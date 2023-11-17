#include "FitnessDataStruct.h"
#include <stdbool.h>

char filename[100], tempDate[11], tempTime[6];
int total = 0, i, compareOne, compareTwo, tempSteps;
bool sorted = false;
FITNESS_DATA data[200];

int main()
{
    printf("Enter Filename: ");
    scanf("%s", filename);
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        printf("Error: Could not find or open the file.\n");
        return 1;
    }
    // stores contents of file into the array, returns total number of records
    total = count_and_store(file, data);
    fclose(file);
    while (sorted == false)
    {
        sorted = true;
        compareOne = data[i].steps;
        for (i = 0; i < total - 1; i++)
        {
            compareTwo = data[i + 1].steps;
            if (compareTwo < compareOne)
            {
                tempSteps = compareOne;
                strcpy(data[i].date, tempDate);
                strcpy(data[i].time, tempTime);
                data[i].steps = compareTwo;
                data[i].date = data[i+1].date;
                data[i].time = data[i+1].time;
                data[i+1].steps = compareTwo;
                data[i+1].date = tempDate;
                data[i+1].time = tempTime;
                sorted = false;
            }

            compareOne = data[i+1].steps;
        }
    }

    FILE *filenew = fopen("FitnessData_2023.csv.tsv", "w");
    for (i = 0; i < total; i++)
    {
        fprintf(filenew, "%s\t%s\t%d\n", data[i].date, data[i].time, data[i].steps);
        fclose(filenew);
    }
}
