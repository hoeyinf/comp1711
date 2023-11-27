#include <stdio.h>

int main()
{
    int vector[5] = {1, 2, 3, 4, 5};

    int *address;

    address = vector;

    printf("\n \n address = %p\n", address);

    printf(" vector = %p\n\n", vector);
    for (int i = 0; i < 5; i++)
    {
        printf("address[%d] = %d,  vector[%d] = %d\n", i, address[i], i, vector[i]);
    }
}