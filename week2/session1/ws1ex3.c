#include <stdio.h>
#include <limits.h>
#include <float.h>

int main (){
    int intmax, charmax;
    double floatmax, doublemax;
    
    intmax = INT_MAX;
    floatmax = FLT_MAX;
    doublemax = DBL_MAX;
    charmax = CHAR_MAX;

    printf("Max of int, float, double, and char are respectively %d, %g, %g, and %d\n", intmax, floatmax, doublemax, charmax);

    return 0;

}