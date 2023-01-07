#include "mathlib.h"

#include <stdio.h>
//Variable to count the number of iterations.
int num_terms_madhava = 1;

//This function performs the madhava approximation for pi. The formula used for this code is found in the assgnment pdf. First iteration is already sovled.
double pi_madhava(void) {
    double return_value = 1;
    double last_iteration = 0;
    double top_half = 1;
    for (int i = 1; absolute(return_value - last_iteration) > EPSILON; i++) {
        last_iteration = return_value;
        num_terms_madhava += 1;
        if (i != 0) {
            top_half = top_half * (-3);
        }
        return_value += (double) (1 / (top_half) / ((2 * i) + 1));
    }
    return sqrt_newton(12) * return_value;
}

//Returns the number of iterations that it took to get the calculations.
int pi_madhava_terms(void) {
    return num_terms_madhava;
}
