#include "mathlib.h"

#include <stdio.h>
//Variable to count the number of iterations.
int num_terms = 0;

//This function performs the Bailey-Borwein-Plouffe approximation for pi. The formula used for this code is found in the assignment pdf.
double pi_bbp(void) {
    double return_value = 0;
    double last_iteration = -1;
    double power_term = 1;
    double term_one = 0;
    double term_two = 0;
    double term_three = 0;
    double term_four = 0;
    for (double i = 0; (return_value - last_iteration) > EPSILON; i++) {
        num_terms += 1;
        last_iteration = return_value;
        if (i != 0) {
            power_term = power_term * 16;
        }
        term_one = 4 / ((8 * i) + 1);
        term_two = 2 / ((8 * i) + 4);
        term_three = 1 / ((8 * i) + 5);
        term_four = 1 / ((8 * i) + 6);
        return_value
            = return_value + (1 / power_term) * (term_one - term_two - term_three - term_four);
    }
    return return_value;
}

//Return the number of iterations that it took to get the calculations.
int pi_bbp_terms(void) {
    return num_terms;
}

