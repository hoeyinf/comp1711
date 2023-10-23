#include "utils.h"

int main() {
    char* filename = "squares.dat";
    FILE *file = open_file(filename, "r");


    int buffer_size = 100;
    char num_buffer[buffer_size];
    float counter = 0, total = 0, mean;

    while (fgets(num_buffer, buffer_size, file) != NULL) {
        total += atoi(num_buffer);
        counter++;
    }

    mean = total/counter;
    printf("%g is the mean of the numbers in that file.\n", mean);
    fclose(file);
    return 0;
}