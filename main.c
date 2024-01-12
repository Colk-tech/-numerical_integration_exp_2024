//
// Created by manaki.ito.ts on 2024/01/12.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "ni_exp_util.c"
#include "simpson.c"

#define PI 3.14159265f

const int PARTITIONS[] = {50, 100, 500, 1000, 2000, 5000, 10000, 20000};
const int NUMBER_OF_PARTITIONS = sizeof(PARTITIONS) / sizeof(PARTITIONS[0]);

float function_of_exercise(float x) {
    return (x * x) + (x) + (1.0f);
}

float function_of_assignment_2(float x) {
    return sqrtf(4.0f - (x * x));
}

float function_of_assignment_7(float x) {
    return (4.0f) / (1 + (x * x));
}

float function_of_assignment_10(float x) {
    return function_of_assignment_2(x);
}

float function_of_assignment_11(float x) {
    return function_of_assignment_7(x);
}

void show_result_for(float (*func_ptr)(float), float a, float b) {
    for (int i = 0; i < NUMBER_OF_PARTITIONS; i++) {
        int n = PARTITIONS[i];

        float *y = (float *) malloc(sizeof(float) * n);

        float *y_calculated = calculate_polynomial(func_ptr, a, b, n, y);

        float h = ((float) b - (float) a) / (float) n;

        float result = simpsons_rule(y_calculated, n, h);

        printf("n = %d, result = %.8f\n", n, result);

        free(y);
    }
}

int main() {
    printf("========== 3. Assignment ==========\n");
    printf("(2)\n");
    show_result_for(function_of_assignment_2, 0.0f, 2.0f);

    printf("\n");
    printf("(7)\n");
    show_result_for(function_of_assignment_7, 0.0f, 1.0f);

    printf("\n");
    printf("(10)\n");
    show_result_for(function_of_assignment_10, 0.0f, 2.0f);

    printf("\n");
    printf("(11)\n");
    show_result_for(function_of_assignment_11, 0.0f, 1.0f);

    return 0;
}
