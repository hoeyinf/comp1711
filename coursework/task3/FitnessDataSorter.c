#include "FitnessDataStruct.h"

char filename[100];
int records;
FITNESS_DATA data[200];

int main()
{
    // user inputs filename, error if file doesn't exist
    printf("Enter Filename: ");
    scanf("%s", filename);
    while (getchar() != '\n')
        ;
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        printf("Error: invalid file\n");
        return 1;
    }

    // checks for correct file format
    if (validate_file(file) == 1)
    {
        fclose(file);
        printf("Error: invalid file\n");
        return 1;
    }

    count_and_store(file, data, &records);
    fclose(file);

    // sorts data, using bubble sort
    sort_data(data, records);

    // creates appropriately named tsv file
    output_tsv(filename, data, records);

    return 0;
}