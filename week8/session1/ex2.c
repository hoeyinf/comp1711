#include <stdio.h>

// top row * left column, top row * right column
// bottom row * left col, bottom row * right col

int multArray(int array[2][3], int array2[3][2])
{
    int productArray[2][2] = {0, 0, 0, 0};
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            productArray[i][i] += array[i][j] * array2[j][i];
            if (i == 0)
            {
                productArray[i][i + 1] += array[i][j] * array2[j][i + 1];
                productArray[i + 1][i] += array[i + 1][j] * array2[j][i];
            }
        }
    }
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
        {
            {
                printf("%d\n", productArray[i][j]);
            }
        }
}

int main()
{
    int arrA[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int arrB[3][2] = {{2, 3}, {4, 5}, {6, 7}};
    multArray(arrA, arrB);
}