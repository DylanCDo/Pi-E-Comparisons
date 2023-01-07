#include "mathlib.h"
#define OPTIONS "aebmrvnsh"

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

//This file is what the user interfaces with to run tests.
int main(int argc, char **argv) {
    int opt = 0;

    bool e_test = false;
    bool b_test = false;
    bool m_test = false;
    bool r_test = false;
    bool v_test = false;
    bool n_test = false;
    bool s_verbose = false;
    bool h_help = false;
    bool default_statement = true;

    //This while loop is what determines what code runs based on what the user inputs on the command line.
    while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
        switch (opt) {
        case 'a':
            e_test = true;
            b_test = true;
            m_test = true;
            r_test = true;
            v_test = true;
            n_test = true;
            default_statement = false;
            break;
        case 'e':
            e_test = true;
            default_statement = false;
            break;
        case 'b':
            b_test = true;
            default_statement = false;
            break;
        case 'm':
            m_test = true;
            default_statement = false;
            break;
        case 'r':
            r_test = true;
            default_statement = false;
            break;
        case 'v':
            v_test = true;
            default_statement = false;
            break;
        case 'n':
            n_test = true;
            default_statement = false;
            break;
        case 's':
            s_verbose = true;
            default_statement = false;
            break;
        case 'h': h_help = true; break;
        }
        if (h_help) {
            default_statement = true;
            e_test = false;
            b_test = false;
            m_test = false;
            r_test = false;
            v_test = false;
            n_test = false;
            s_verbose = false;
        }
    }

    //The following if statements are to determine which test/statement should be ran. Furthermore, the nested if statements determine whether or not the amount of iterations for each test should be shown.
    if (e_test) {
        printf("e() = %16.15lf, M_E = %16.15lf, diff = %16.15lf\n", e(), M_E, absolute(e() - M_E));
        if (s_verbose) {
            printf("e() terms = %d\n", e_terms());
        }
    }
    if (b_test) {
        printf("pi_bbp() = %16.15lf, M_PI = %16.15lf, diff = %16.15lf\n", pi_bbp(), M_PI,
            absolute(pi_bbp() - M_PI));
        if (s_verbose) {
            printf("pi_bbp() terms = %d\n", pi_bbp_terms());
        }
    }
    if (m_test) {
        printf("pi_madhava() = %16.15lf, M_PI = %16.15lf, diff = %16.15lf\n", pi_madhava(), M_PI,
            absolute(pi_madhava() - M_PI));
        if (s_verbose) {
            printf("pi_madhava() terms = %d\n", pi_madhava_terms());
        }
    }
    if (r_test) {
        printf("pi_euler() = %16.15lf, M_PI = %16.15lf, diff = %16.15lf\n", pi_euler(), M_PI,
            absolute(pi_euler() - M_PI));
        if (s_verbose) {
            printf("pi_euler() terms = %d\n", pi_euler_terms());
        }
    }
    if (v_test) {
        printf("pi_viete() = %16.15lf, M_PI = %16.15lf, diff = %16.15lfn", pi_viete(), M_PI,
            absolute(pi_viete() - M_PI));
        if (s_verbose) {
            printf("pi_viete() factors = %d\n", pi_viete_factors());
        }
    }
    if (n_test) {
        for (double i = 0; i < 10; i += 0.1) {
            printf("sqrt_newton(%0.6lf) = %16.15lf, sqrt(%0.6lf) = %16.15lf, diff = %16.15lf\n", i,
                sqrt_newton(i), i, sqrt(i), absolute(sqrt_newton(i) - sqrt(i)));
            if (s_verbose) {
                printf("sqrt_newton() terms = %d\n", sqrt_newton_iters());
            }
        }
    }
    if (default_statement) {
        printf("SYNOPSIS\n   A test harness for the small numerical library.\n\n");
        printf("USAGE\n   ./mathlib-test [-aebmrvnsh]\n\n");
        printf("OPTIONS\n");
        printf("  -a   Runs all tests.\n");
        printf("  -e   Runs e test.\n");
        printf("  -b   Runs BBP pi test.\n");
        printf("  -m   Runs Madhava pi test.\n");
        printf("  -r   Runs Euler pi test.\n");
        printf("  -v   Runs Viete pi test.\n");
        printf("  -n   Runs Newton square root tests.\n");
        printf("  -s   Print verbose statistics.\n");
        printf("  -h   Display program synopsis and usage.\n");
    }

    return 0;
}
