//
// Created by manaki.ito.ts on 2024/01/19.
//

#ifndef MONTE_CARLO_EG_C
#define MONTE_CARLO_EG_C

#include <stdio.h>
#include <stdlib.h>

#define NUM 10000000

double rnd(void) {
    return (double) rand() / RAND_MAX;
}

int main(void) {
    double x, y, pi;
    int i, in = 0;

    for (i = 0; i < NUM; i++) {
        x = rnd();
        y = rnd();
        if (x * x + y * y <= 1.0) {
            in++;
        }
    }

    pi = 4.0 * in / NUM;

    printf("pi=%f\n", pi);

    return 0;
}

#endif //MONTE_CARLO_EG_C
