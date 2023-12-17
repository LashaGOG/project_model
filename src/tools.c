#include "../include/tools.h"
#include "../include/fft.h"
#include "../include/polynom.h"

/* AUTHORS : TAN Philippe
             GOGRITCHIANI Lasha
             CHEN Virginie
*/

double measure_execution_time(int *p1, int *p2, int n1, int n2, int algo)
{
    /*  return execution time for given algorithm
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
int find_max_instance_size(int algo)
{
    /* return the size of instance for which execution of given algorithm and graph generation time exceeds 1s */
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
        max_n += 1000;
        printf("n = %d exec_time = %lf\n", max_n, exec_time);
        free(p1);
        free(p2);
    } while (exec_time < 1);
    printf("Max instance size found\n");

    return max_n;
}

int *generate_tab_sizes(int max_size, int nb_sizes)
{
    /* cut max_size in nb_sizes even parts and return sizes as an array */
    int *sizes = (int *)calloc(nb_sizes, sizeof(int));
    for (int i = 1; i < nb_sizes + 1; i++)
    {
        sizes[i - 1] = i * (max_size / nb_sizes);
    }
    return sizes;
}

// double *compute_mean_exec_time(int *tab_sizes, int nb_sizes, int n)
// {
//     /* menerate mean execution time for each algorithm */
//     double *mean_exec_times = (double *)calloc(nb_sizes, sizeof(double));
// }

void arrays_to_file(int *sizes, int nb_sizes, double *t_naive, double *t_fft)
{
    FILE *fptr;
    fptr = fopen("exec_times.txt", "w");
    for (int i = 0; i < nb_sizes; i++)
    {
        fprintf(fptr, "%d %lf %lf\n", sizes[i], t_naive[i], t_fft[i]);
    }
    fclose(fptr);
}