#include <stdio.h>
#include "../include/complex.h"

complex create_complex(double a, double b){
    complex z = calloc(sizeof(complex));
    z.re = a;
    z.im = b;
    return z;
}

void delete_complex(complex z){
    free(z);
}

void print_complex(complex z){
    printf("Voici la partie reelle %ld \n", z.re);
    printf("Voici la partie imaginaire %ld", z.im);
}
