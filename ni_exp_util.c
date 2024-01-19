//
// Created by manaki.ito.ts on 2024/01/12.
//

#ifndef NI_EXP_UTIL_C
#define NI_EXP_UTIL_C

float *calculate_polynomial(float (*func_ptr)(float), float a, float b, int n, float *y) {
    float h = (b - a) / (float) n;

    for (int i = 0; i < n; i++) {
        float x = a + (h * (float) i);
        y[i] = func_ptr(x);
    }

    return y;
}

double *calculate_polynomial_double(double (*func_ptr)(double), double a, double b, int n, double *y) {
    double h = (b - a) / (double) n;

    for (int i = 0; i < n; i++) {
        double x = a + (h * (double) i);
        y[i] = func_ptr(x);
    }

    return y;
}

#endif // NI_EXP_UTIL_C
