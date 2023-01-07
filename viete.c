#include "mathlib.h"

#include <stdio.h>

//Variable to count the number of iterations.
int factors = 0;

//This function performs the viete approximation for pi. The formula used for this code is found in the assignment pdf.
double pi_viete(void) {
    double return_value = 1;
    double last_iteration = 0;
    double a = sqrt_newton(2);

    while (absolute(return_value - last_iteration) > EPSILON) {
        last_iteration = return_value;
        return_value = return_value * (a / 2);
        a = sqrt_newton(2 + a);
        factors += 1;
    }
    return 2 / return_value;
}

//Return the number of iterations that it took to get the calculations.
int pi_viete_factors(void) {
    return factors;
}
