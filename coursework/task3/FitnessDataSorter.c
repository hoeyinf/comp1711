#include "FitnessDataStruct.h"

char filename[100];
int records;
bool error;
FITNESS_DATA data[200];

int main()
{
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
    error = validate_store_count(file, data, &records);
    if (error == true)
    {
        printf("Error: invalid file\n");
        fclose(file);
        return 1;
    }
    fclose(file);

    sort_data(data, records);

    output_tsv(filename, data, records);

    return 0;
}