#include "mathlib.h"

#include <stdio.h>
//Variable to count the number of iterations.
int num_terms_euler = 1;

//This function performs the euler approximation for pi. The formula used for this code is found in the assignment pdf. First iteration is solved.
double pi_euler(void) {
    double return_value = 1;
    double fraction = 1;
    for (double i = 2; (fraction) > EPSILON; i++) {
        num_terms_euler += 1;
        fraction = 1 / (i * i);
        return_value += fraction;
    }
    return sqrt_newton(6 * return_value);
}

//Return the number of iterations that it took to get the calculations.
int pi_euler_terms(void) {
    return num_terms_euler;
}
