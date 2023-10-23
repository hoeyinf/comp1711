#include "utils.h"

int main()
{
    char *filename = "numbers.dat";

    FILE *file = open_file(filename, "a+"); 

    int buffer_size = 100, count = 0;
    char line_buffer[buffer_size];
    float total = 0, mean;

    while (fgets(line_buffer, buffer_size, file) != NULL) {
        total += atof(line_buffer);
        count++;
    }

    mean = total/count;
    fprintf(file, "\n%g", mean);

    fclose(file);
    return 0;
}