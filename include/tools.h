#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h> // FOR MACOS ?
#include <time.h>

/* AUTHORS : TAN Philippe
             GOGRITCHIANI Lasha
             CHEN Virginie
*/

#ifndef TOOLS
#define TOOLS

double measure_execution_time(int *p1, int *p2, int n1, int n2, int algo);
int find_max_size(int algo);
void measure_execution_time_mean(int size, int number, double * t_naive, double * t_fft);
void mean_execution_time_algos(int number, int N_max, int div, int * tab_sizes, double * tab_time_naive, double * tab_time_fft);

int find_critical_size();
int find_critical_size_mean();

void arrays_to_file(int size, int * tab_sizes, double *tab_time_naive, double *tab_time_fft);

void mean_exec_time_pow(int number, int size, int * tab_sizes, double * tab_time_naive, double * tab_time_fft);

#endif // TOOLS