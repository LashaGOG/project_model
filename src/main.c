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

    /******************** FIND MAX INSTANCE SIZE FOE EACH ALGORITHM WITH EXEC_TIME <= 1s ********************/

    // int max_size_naive = find_max_instance_size(0); // naive algo
    // printf("Maximum instance size for naive multiplication algorithm found : %d\n", max_size_naive);
    // // Lasha :    n = 23000, exec_time = 1.032500
    // // Virginie : n = 25000, exec_time = 1.013297
    // // Philippe : n = exec_time =

    // int max_size_fft = find_max_instance_size(1); // fft based algo
    // printf("Maximum instance size for fft based multiplication algorithm found : %d\n", max_size_fft);
    // // Lasha :    n = 65000, exec_time = 0.175214 and SegFault for n > 66000
    // // Virginie : n = 65000, exec_time = 0.138843 and SegFault for n > 66000
    // // Philippe : n =

    /******************** OTHER TESTS ********************/

    // int max_size = 10000;
    // int nb_sizes = 5;
    // int *sizes = generate_tab_sizes(max_size, nb_sizes);

    // for (int i = 0; i < nb_sizes; i++)
    // {
    //     printf("%d ", sizes[i]);
    // }
    // printf("\n");

    // double t_naive[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
    // double t_fft[5] = {6.0, 7.0, 8.0, 9.0, 10.0};

    // arrays_to_file(sizes, nb_sizes, t_naive, t_fft);

    // free(sizes);


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

    // int critical_size = find_critical_size();
    // printf("The size for which fft multiplication become faster is : %d \n", critical_size);

    /*Création des tableaux de données pour tracer les courbes de temps d'éxécution moyen*/
    int div = 15;
    int number = 5;
    int N_max = 10000;
    double * tab_time_naive = calloc(div, sizeof(double));
    double * tab_time_fft = calloc(div, sizeof(double));
    int * tab_sizes = malloc(sizeof(int[div]));

    mean_execution_time_algos(number,N_max,div,tab_sizes,tab_time_naive,tab_time_fft);

    // for (int i =0;i<div;i++){
    //     printf("i = %d \n", i+1);
    //     printf("time naive = %lf \n", tab_time_naive[i]);
    //     printf("time fft = %lf \n", tab_time_fft[i]);
    // }

    arrays_to_file(div,tab_sizes,tab_time_naive,tab_time_fft);

    free(tab_time_naive);
    free(tab_time_fft);
    free(tab_sizes);
    /*Fin */


    free(p1);
    free(p2);

    return 0;
}