#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double xcoor;
    double ycoor;
} point;

int main(){
    point points[10];
    char xcoor[10], ycoor[10];
    for(int i=0;i<10;i++){
        printf("Enter x-coordinate #%d: \n", i+1);
        scanf("%s", xcoor);
        points[i].xcoor = atof(xcoor);

        printf("Enter y-coordinate #%d: \n", i+1);
        scanf("%s", ycoor);
        points[i].ycoor = atof(ycoor);
        printf("(%.2f, %.2f)\n", points[i].xcoor, points[i].ycoor);
    }
}