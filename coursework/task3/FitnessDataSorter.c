#include "FitnessDataStruct.h"

char filename[100];
int records;
bool error;
FITNESS_DATA data[200];

int main()
{
    // user inputs filename, error if file doesn't exist
    printf("Enter Filename: ");
    scanf("%s", filename);
    while (getchar() != '\n');
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        printf("Error: invalid file\n");
        return 1;
    }

    // function will check for correct file format while reading/storing data
    // returns true if file is invalid
    error = validate_store_count(file, data, &records);
    fclose(file);
    if (error == true)
    {
        printf("Error: invalid file\n");
        return 1;
    }

    // sorts data, using bubble sort
    sort_data(data, records);

    // creates appropriately named tsv file
    output_tsv(filename, data, records);

    return 0;
}