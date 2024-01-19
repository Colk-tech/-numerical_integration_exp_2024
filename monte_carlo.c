//
// Created by manaki.ito.ts on 2024/01/19.
//

#ifndef MONTE_CARLO_C
#define MONTE_CARLO_C

#include <stdbool.h>
#include <stdlib.h>

#include "ni_exp_util.c"

#define is_in(x, y, func_ptr) y <= func_ptr(x)

double monte_carlo_integration(double (*func_ptr)(double), double a, double b, double y_max, double n) {
    double count = 0;

    for (int i = 0; i < n; i++) {
        double x_i = random_double(a, b);
        double y_i = random_double(0, y_max);

        if (is_in(x_i, y_i, func_ptr)) {
            count++;
        }
    }

    double result = (b - a) * (y_max) / n * count;

    return result;
}

#endif //MONTE_CARLO_C
