//
// Created by manaki.ito.ts on 2024/01/12.
//

#ifndef SIMPSON_C
#define SIMPSON_C

float simpsons_rule(const float *y, int n, float h) {
    float result = 0;

    for (int i = 0; i < n; i++) {
        if (i == 0 || i == n - 1) {
            result += y[i];
        } else if (i % 2 == 0) {
            result += 2 * y[i];
        } else {
            result += 4 * y[i];
        }
    }

    result *= h / 3;

    return result;
}

float simpsons_3_8_rule(const float *y, int n, float h) {
    float result = 0;

    for (int i = 0; i < n; i++) {
        if (i == 0 || i == n - 1) {
            result += y[i];
        } else if (i % 3 == 0) {
            result += 2 * y[i];
        } else {
            result += 3 * y[i];
        }
    }

    result *= (3 * h) / 8;

    return result;
}

#endif //SIMPSON_C