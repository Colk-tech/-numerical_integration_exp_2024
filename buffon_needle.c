//
// Created by manaki.ito.ts on 2024/02/22.
//

#ifndef BUFFON_NEEDLE_C
#define BUFFON_NEEDLE_C

#define NUM 10000000

#define H 1.0f
#define L H / 2.0f

#include <stdio.h>
#include <math.h>

#include "ni_exp_util.c"

int main(void) {
    double x, y, pi, p;
    int i, touched = 0;

    for (i = 0; i < NUM; i++) {
        x = random_double(0, H / 2);
        y = random_double(0, M_PI / 2);

        if (x <= L * sin(y)) {
            touched++;
        }
    }

    p = (double) touched / NUM;
    pi = 1 / p;

    printf("pi=%f\n", pi);

    return 0;
}

#endif //BUFFON_NEEDLE_C
