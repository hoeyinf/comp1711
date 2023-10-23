#include <stdio.h>

int main() {
    char* filename = "data.txt";
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }


    int buffer_size = 100, numbers[1000], counter = 0; //number of characters going to be read per line (100 is standard)
    char line_buffer[buffer_size]; //making a string that will hold each line as it's read in

    //"while there's still data in the file". Read into line_buffer, 100 size, from file name.
    while (fgets(line_buffer, buffer_size, file) != NULL) {
        printf("%d\n", atoi(line_buffer));
        numbers[counter] = atoi(line_buffer);
        counter++;
    }

    fclose(file);
    return 0;
}