#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sum_marks(int arr[][5]){
    int sums[4] = {0, 0, 0, 0};
    
}

int main()
{
    int marks[4][5];
    srand(time(NULL));
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            marks[i][j] = rand() % 26;
            printf("%d\n", marks[i][j]);
        }
    }
}