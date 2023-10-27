#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double xcoor;
    double ycoor;
} point;

int main(){
    char xcoor[10], ycoor[10];
    double euclideanDistance;
    point points[2];
    for(int i=0; i<2; i++){
        printf("Enter x-coordinate #%d: \n", i+1);
        scanf("%s", xcoor);
        points[i].xcoor = atof(xcoor);

        printf("Enter y-coordinate #%d: \n", i+1);
        scanf("%s", ycoor);
        points[i].ycoor = atof(ycoor);

        printf("Coordinate #%d: (%g, %g)\n", i+1, points[i].xcoor, points[i].ycoor);
    }

    euclideanDistance = sqrt(pow(points[0].xcoor-points[1].xcoor,2)+pow(points[0].xcoor-points[1].xcoor,2));
    printf("Euclidean distance of the two points is %f\n", euclideanDistance);
}