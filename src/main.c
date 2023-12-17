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
    int max_size = 10000;
    int nb_sizes = 5;
    int *sizes = generate_tab_sizes(max_size, nb_sizes);

    for (int i = 0; i < nb_sizes; i++)
    {
        printf("%d ", sizes[i]);
    }
    printf("\n");

    double t_naive[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
    double t_fft[5] = {6.0, 7.0, 8.0, 9.0, 10.0};

    arrays_to_file(sizes, nb_sizes, t_naive, t_fft);

    free(sizes);
    return 0;
}