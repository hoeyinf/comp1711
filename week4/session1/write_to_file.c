#include "utils.h"

int main()
{
    char *filename = "data.txt";

    FILE *file = open_file(filename, "w"); // or "a", "w+", "a+"

    int number, num_lines;
    float total = 0, mean;

    printf("Type how many you want to enter numbers: ");
    scanf("%d", &num_lines);
    char* string;
    
    printf("Type %d numbers: ", num_lines);
    
    for (int i = 0; i < num_lines; i++)
    {
        scanf("%d", &number);
        fprintf(file, "%d\n", number);
        total += number;
    }

    mean = total/num_lines;
    fprintf(file, "%g\n", mean);

    fclose(file);
    return 0;
}