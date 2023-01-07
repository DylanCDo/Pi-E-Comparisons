#include "mathlib.h"

#include <stdio.h>
//Variable to count the number of iterations.
int num_terms_e = 1;

//This function performs the euler approximation for e. This is done by taking the summation of 1/k**2. The first term is already solved.
double e(void) {
    double return_value = 1;
    double last_iteration = 0;
    double power_num = 1;
    double fraction = 1;
    for (int i = 1; (fraction) > EPSILON; i++) {
        last_iteration = return_value;
        power_num *= i;
        fraction = 1 / power_num;
        num_terms_e += 1;
        return_value += fraction;
    }

    return return_value;
}

//Returns the number of iterations that it took to get the calculations.
int e_terms() {
    return num_terms_e;
}

