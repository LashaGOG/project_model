#include <stdio.h>
#include "../include/complex.h"
#include "../include/polynom.h"
#include "../include/fft.h"
#include "../include/tools.h"

/* AUTHORS : TAN Philippe
             GOGRITCHIANI Lasha
             CHEN Virginie
*/

int main()
{

    srand(time(NULL));

    int n = 5;
    int *p1 = random_polynom(n, 1, 100);
    int *p2 = random_polynom(n, 1, 100);
    printf("P1 = ");
    print_polynom(p1, n);
    printf("P2 = ");
    print_polynom(p2, n);
    double exec_time_naive = measure_execution_time(p1, p2, n, n, 0);
    double exec_time_fft = measure_execution_time(p1, p2, n, n, 1);
    printf("execution time for naive algo = %lfs\n", exec_time_naive);
    printf("execution time for fft based algo = %lfs\n", exec_time_fft);

    // int max_size_naive = find_max_instance_size(0);
    // printf("Maximum instance size for naive multiplication algorithm found : %d\n", max_size_naive);

    // int max_size_fft = find_max_instance_size(1);
    // printf("Maximum instance size for fft based multiplication algorithm found : %d\n", max_size_fft);

    int critical_size = find_critical_size();
    printf("The size for which fft multiplication become faster is : %d \n", critical_size);

    free(p1);
    free(p2);

    return 0;
}