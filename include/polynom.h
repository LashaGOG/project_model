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

int* naive_algo(int* p1,int* p2, int len1, int len2);
void print_polynom(int* p, int n);
void delete_polynom(int* p);
int generate_random_real(int a, int b);
int* random_polynom(int deg, int a, int b);












#endif // POLYNOM