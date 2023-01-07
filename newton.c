#include "mathlib.h"

#include <stdio.h>

//Variable to count the number of iterations.
int count = 0;

//This function performs newton's method of approximating a square root. The formula used for this code can be found in the assignment pdf. Additionally, some of the code used for this can be found in the assignment pdf.
double sqrt_newton(double num) {
    count = 0;
    double z = 0;
    double return_value = 1;

    while (absolute(return_value - z) > EPSILON) {
        count += 1;
        z = return_value;
        return_value
            = (double) (0.5
                        * (z + num / z)); //This piece of code can be found in the assignment pdf.
    }
    return return_value;
}

//Return the number of iterations that it took to get the calculations.
int sqrt_newton_iters() {
    return count;
}
