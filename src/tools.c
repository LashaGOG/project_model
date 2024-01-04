#include "../include/tools.h"
#include "../include/fft.h"
#include "../include/polynom.h"

/* AUTHORS : TAN Philippe
             GOGRITCHIANI Lasha
             CHEN Virginie
*/

double measure_execution_time(int *p1, int *p2, int n1, int n2, int algo)
{
    /*  return execution time for a given algorithm
     *  algo = 0, execute naive multiplication algorithm
     *  algo = 1, fft_based multiplication
     */

    clock_t start, end;
    int *p;
    if (algo == 0)
    {
        start = clock();
        p = naive_algo(p1, p2, n1, n2);
        end = clock();
    }
    else if (algo == 1)
    {
        start = clock();
        p = multiply_poly_fft(p1, p2, n1, n2);
        end = clock();
    }
    else
    {
        perror("Unknown algorithm\n");
        exit(1);
    }
    if (p)
        free(p);

    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

/* hi */
int find_max_size(int algo)
{
    /* Returns the size of the polynom for which the execution time of the given algorithm exceeds 1s */

    int max_n = 1000;
    double exec_time = 0;
    int *p1, *p2;

    if (algo != 0 && algo != 1)
    {
        perror("Unknown algorithm\n");
        exit(1);
    }

    printf("Searching the max instance size...\n");
    do
    {
        p1 = random_polynom(max_n, 0, 100);
        p2 = random_polynom(max_n, 0, 100);
        exec_time = measure_execution_time(p1, p2, max_n, max_n, algo);

        max_n += 1000; // Increase the polynomial size by 1000 for testing the next iteration

        // printf("n = %d exec_time = %lf\n", max_n, exec_time);
        free(p1);
        free(p2);

    } while (exec_time < 1);
    printf("Max instance size found n = %d, exec_time = %lf\n", max_n, exec_time);

    return max_n;
}

void measure_execution_time_mean(int size, int number, double *t_naive, double *t_fft)
{
    /*  Calculates the average execution time over number instances for both the naive algorithm and
     *   the FFT algorithm for multiplying two polynomials of size 'size'.
     *   The execution time for each algorithm is calculated on the same instance.
     */

    int *p1, *p2;
    double time_naive = 0.0;
    double time_fft = 0.0;

    for (int i = 0; i < number; i++)
    {
        p1 = random_polynom(size, 0, 100);
        p2 = random_polynom(size, 0, 100);

        // Adding the time execution of each execution on random polynoms
        time_naive += measure_execution_time(p1, p2, size, size, 0);
        time_fft += measure_execution_time(p1, p2, size, size, 1);

        free(p1);
        free(p2);
    }

    // Calculating the mean value of those times
    *t_naive = (double)time_naive / number;
    *t_fft = (double)time_fft / number;
}

void mean_execution_time_algos(int number, int N_max, int div, int *tab_sizes, double *tab_time_naive, double *tab_time_fft)
{
    /*  fill the array tab_time and tab_sizes with the mean execution time for every sizes between
     *  N_max / div and N_max for both algorithm
     */

    double t_naive = 0.0;
    double t_fft = 0.0;
    int k = N_max / div; // Avoids recalculating at each iteration

    for (int i = 1; i * k <= N_max; i++)
    {

        measure_execution_time_mean(i * k, number, &t_naive, &t_fft);

        // Fill the array of times executions and sizes on which we apply our both algorithms
        tab_time_naive[i - 1] = t_naive;
        tab_time_fft[i - 1] = t_fft;
        tab_sizes[i - 1] = i * k;
    }
}

void mean_exec_time_pow(int number, int size, int *tab_sizes, double *tab_time_naive, double *tab_time_fft)
{
    /*Similar to mean_execution_time_algos, but this function only considers polynomial sizes that are powers of 2*/

    double t_naive = 0.0;
    double t_fft = 0.0;

    for (int i = 0; i < size; i++)
    {

        measure_execution_time_mean(pow(2,i), number, &t_naive, &t_fft);
        tab_time_naive[i] = t_naive;
        tab_time_fft[i] = t_fft;
        tab_sizes[i] = pow(2, i);
    }
}

int find_critical_size()
{
    /* find the size of polynom for which fft multiplication algorithm starts to be faster than naive multiplication */
    int max_n = 10;
    double t_naive;
    double t_fft;
    
    do
    {
        measure_execution_time_mean(max_n, 20, &t_naive, &t_fft);
        max_n += 10;
        } while (t_naive < t_fft);
    return max_n;
}

int find_critical_size_mean()
{
    /*donne en moyenne sur 50 instances la taille de polynôme pour laquelle la fft devient plus rapide*/
    int val = 0;
    int n = 10;
    for (int i = 0; i < n; i++)
    {
        val += find_critical_size();
    }
    int critical_size = val / n;
    printf("Critical size : %d\n", critical_size);
    return critical_size;
}

void arrays_to_file(int size, int *tab_sizes, double *tab_time_naive, double *tab_time_fft)

/*Converts the data arrays into a file. Overwrites the existing file with each new call*/

{
    FILE *fptr;
    fptr = fopen("exec_times.txt", "w");
    for (int i = 0; i < size; i++)
    {
        fprintf(fptr, "%d %lf %lf\n", tab_sizes[i], tab_time_naive[i], tab_time_fft[i]);
    }
    fclose(fptr);
    printf("data saved as \"exec_times.txt\"\n");
}