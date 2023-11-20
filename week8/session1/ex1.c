#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initArray(int array[][3])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            array[i][j] = rand() % 10;
        }
    }
}

void transArray(int rows, int cols, int array[rows][cols], int newarray[cols][rows])
{
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            newarray[i][j] = array[j][i];
        }
    }
}

void printArray(int rows, int cols, int array[rows][cols])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

int main()
{

    int arr[2][3];
    // need to seed srand(), or else rand() will remain the same random numbers
    srand(time(NULL));
    initArray(arr);
    printf("Initial array: \n");
    printArray(2, 3, arr);
    int newarr[3][2];
    transArray(2, 3, arr, newarr);
    printf("Transposed array: \n");
    printArray(3, 2, newarr);
    return 0;
}