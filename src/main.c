#include <stdio.h>
#include "../include/complex.h"
#include "../include/polynom.h"
#include "../include/fft.h"
#include "../include/tools.h"

/* AUTHORS : TAN Philippe
             GOGRITCHIANI Lasha
             CHEN Virginie
*/

#define POLY_SIZE_ANY 1 // define to 1 for execution on polynoms of any degree, 0 for degree = pow(2,k)

int main()
{
    srand(time(NULL));

    /******************** Multipling two random polynoms using naive and fft based algorithms ********************/

    int size1 = generate_random_real(1, 5); // size of polynoms between 1 and 5
    int size2 = generate_random_real(1, 5);

    int *poly1 = random_polynom(size1, 1, 100); // coefficients of polynoms between 1 and 100
    int *poly2 = random_polynom(size1, 1, 100);

    printf("=============== Multipling two random polynoms ==============\n");
    printf("poly1: ");
    print_polynom(poly1, size1);
    printf("poly2: ");
    print_polynom(poly2, size2);

    int *result_naive1 = naive_algo(poly1, poly2, size1, size2); // naive
    printf("Naive Result : ");
    print_polynom(result_naive1, size1 + size2 - 1);

    int *result_fft1 = multiply_poly_fft(poly1, poly2, size1, size2); // fft
    printf("FFT Result : ");
    print_polynom(result_naive1, size1 + size2 - 1);

    // liberate memory
    if (poly1)
        free(poly1);
    if (poly2)
        free(poly2);
    if (result_naive1)
        free(result_naive1);
    if (result_fft1)
        free(result_fft1);
    printf("========================== Analyze ==========================\n");

    /******************** FIND N_max SIZE FOE EACH ALGORITHM WITH EXEC_TIME < 1s ********************/

    // find_max_size(0);       //Naive Algorithm
    // // Lasha :    n = 23000, exec_time = 1.032500
    // // Virginie : n = 26000, exec_time = 1.017754
    // // Philippe : n = 24000, exec_time = 1.071993

    // find_max_size(1);       //FFT Algorithm
    // // Lasha :    n = 65000, exec_time = 0.175214 and SegFault for n > 66000
    // // Virginie : n = 65000, exec_time = 0.138843 and SegFault for n > 66000
    // // Philippe : n = 65000, exec_time = 0.190115 and SegFault for n > 66000
    printf("==============================================================\n");

    /******************** FIND CRITICAL SIZE I.E. SIZE WHERE FFT BECOMES MORE EFFICENT THAN NAIVE ********************/

    int crit_size = find_critical_size_mean();
    printf("Result found: FFT-based polynomial multiplication becomes more efficient than the naive approach at a size of %d\n", crit_size);

    /* Creation of arrays to plot graphs */

    int N_max = 25000; // degree max of poly
    int number = 15;   // number of instances to use to calculating mean execution time on each size of instance
    double *tab_time_naive, *tab_time_fft;
    int *tab_sizes;
    int size;

    if (POLY_SIZE_ANY == 1)
    {
        size = 25; // divide N_max in size chunks
        tab_time_naive = calloc(size, sizeof(double));
        tab_time_fft = calloc(size, sizeof(double));
        tab_sizes = malloc(sizeof(int[size]));
        printf("Measuring mean execution time for maximum for polynoms of any size. \nMaximum instance size : %d divided in %d equal parts\n", N_max, size);
        mean_execution_time_algos(number, N_max, size, tab_sizes, tab_time_naive, tab_time_fft); // exec_time for polynoms of any size
    }

    else
    {
        // Create an array containing powers of 2
        size = 16;
        tab_time_naive = calloc(size, sizeof(double));
        tab_time_fft = calloc(size, sizeof(double));
        tab_sizes = malloc(sizeof(int[size]));
        printf("Measuring mean execution time for polynoms of size pow(2, k). \nMaximum power of 2 : pow(2,%d) \n", size - 1);
        mean_exec_time_pow(number, size, tab_sizes, tab_time_naive, tab_time_fft); // exec_time for polynoms of size that is power of two
    }

    printf("Writing data to file...\n");
    arrays_to_file(size, tab_sizes, tab_time_naive, tab_time_fft);

    if (tab_time_naive)
        free(tab_time_naive);
    if (tab_time_fft)
        free(tab_time_fft);
    if (tab_sizes)
        free(tab_sizes);

    printf("Execution completed\n");
    printf("To visualize graphs type : \"python3 exec_times.txt\"\n");
    /******************** End ********************/

    return 0;
}