#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/* AUTHORS : TAN Philippe
             GOGRITCHIANI Lasha
             CHEN Virginie
*/

#ifndef POLYNOM
#define POLYNOM

double* naive_algo(double* p1,double* p2, int len1, int len2);
void print_polynom(double* p, int n);
void delete_polynom(double* p);
double generate_random_real(double a, double b);
double* random_polynom(int deg, int a, int b);












#endif // POLYNOM