#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double xcoor;
    double ycoor;
} point;

int main(){
    char num_points[2], xcoor[10], ycoor[10];
    int num;
    double totalx, totaly, total = 0, manhattan;
    
    printf("Enter number of points: \n");
    scanf("%s", num_points);
    num = atoi(num_points);

    point points[num+1];

    for(int i=0;i<num;i++){
        printf("Enter x-coordinate #%d: \n", i+1);
        scanf("%s", xcoor);
        points[i].xcoor = atof(xcoor);

        printf("Enter y-coordinate #%d: \n", i+1);
        scanf("%s", ycoor);
        points[i].ycoor = atof(ycoor);
        printf("Coordinates #%d: (%.2f, %.2f)\n", i+1, points[i].xcoor, points[i].ycoor);
    }

    for(int i=1;i<num;i++){
        totalx = abs(points[i-1].xcoor - points[i].xcoor);
        totaly = abs(points[i-1].ycoor - points[i].ycoor);
        total += totalx + totaly;
    }

    manhattan = total/(num+1);

    printf("Manhattan distance for points is: %f\n", manhattan);
}