#include "FitnessDataSorter.h"

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
        printf("Error: invalid file\n");
        return 1;
    }
    // stores contents of file into the array, returns total number of records
    total = count_and_store(file, data);
    fclose(file);

    sort_data(data, total);

    // filename changed to have .tsv at the end of it
    strcat(filename, ".tsv");
    // creates file, writes contents of sorted array into it (tsv format)
    FILE *filenew = fopen(filename, "w");
    for (i = 0; i < total; i++)
    {
        fprintf(filenew, "%s\t%s\t%d\n", data[i].date, data[i].time, data[i].steps);
    }
    fclose(filenew);
    printf("Data sorted and written to %s\n", filename);
    return 0;
}