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
    /******************* OTHER TESTS ********************/

    /******************** FIND N_max SIZE FOE EACH ALGORITHM WITH EXEC_TIME < 1s ********************/
    // find_max_size(0);       //Naive Algorithm
    // // Lasha :    n = 23000, exec_time = 1.032500
    // // Virginie : n = 26000, exec_time = 1.017754
    // // Philippe : n = exec_time =

    // find_max_size(1);       //FFT Algorithm
    // // Lasha :    n = 65000, exec_time = 0.175214 and SegFault for n > 66000
    // // Virginie : n = 65000, exec_time = 0.138843 and SegFault for n > 66000
    // // Philippe : n =

    // /******************** End ********************/

    /*Création des tableaux de données pour tracer les courbes de temps d'éxécution moyen*/
    int number = 15;
    int N_max = 25000;
    int div = 25;
    double * tab_time_naive = calloc(div, sizeof(double));
    double * tab_time_fft = calloc(div, sizeof(double));
    int * tab_sizes = malloc(sizeof(int[div]));

    mean_execution_time_algos(number,N_max,div,tab_sizes,tab_time_naive,tab_time_fft);
    // mean_exec_time_2(number,N_max,tab_sizes,tab_time_naive,tab_time_fft);

    arrays_to_file(div,tab_sizes,tab_time_naive,tab_time_fft);

    free(tab_time_naive);
    free(tab_time_fft);
    free(tab_sizes);
    /******************** End ********************/


    return 0;
}