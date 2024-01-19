//
// Created by manaki.ito.ts on 2024/01/19.
//

#ifndef MONTE_CARLO_MAIN_C
#define MONTE_CARLO_MAIN_C

#include <stdio.h>
#include <math.h>

#include "monte_carlo.c"

#define N 10000000

double function_of_assignment_mc_1(double x) {
    return (x * x) + (x) + 1;
}

double function_of_assignment_mc_2(double x) {
    return sqrt(4 - (x * x));
}

double function_of_assignment_mc_3(double x) {
    return 4 / (1 + (x * x));
}

double area_of_ellipse(int n) {
    double x, y, S;
    int i, in = 0;

    for (i = 0; i < n; i++) {
        x = random_double(0, 2);
        y = random_double(0, 1);

        if ((x * x / 4) + (y * y) <= 1.0) {
            in++;
        }
    }

    S = (double) 8 * in / n;

    return S;
}

int main(void) {
    printf("========== Assignment ( Monte carlo ) ==========\n");

    printf("4. Area of ellipse\n");
    printf("N = %d, S = %f\n", N, area_of_ellipse(N));
    printf("\n");

    printf("5. Monte carlo integration\n");
    printf("(1)\n");
    printf("N = %d, result = %f\n", N, monte_carlo_integration(function_of_assignment_mc_1, 0, 1, 3, N));

    printf("(2)\n");
    printf("N = %d, result = %f\n", N, monte_carlo_integration(function_of_assignment_mc_2, 0, 2, 2, N));

    printf("(3)\n");
    printf("N = %d, result = %f\n", N, monte_carlo_integration(function_of_assignment_mc_3, 0, 1, 4, N));

    return 0;
}

#endif //MONTE_CARLO_MAIN_C
