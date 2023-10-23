#include "utils.h"

int main()
{
    char *filename = "squares.dat";

    FILE *file = open_file(filename, "w");

    int number, num_lines;

    printf("Type how many numbers you want to enter: \n");
    scanf("%d", &num_lines);
    
    printf("Type %d numbers: \n", num_lines);
    
    for (int i = 0; i < num_lines; i++)
    {
        scanf("%d", &number);
        fprintf(file, "%d\n", number*number);
    }

    fclose(file);
    return 0;
}