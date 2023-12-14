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


double measure_execution_time_mean(int algo, int size, int number)
{
    /*  return the mean execution time of the multiplication(for a given algorithm) of polynoms of size size 
     *  algo = 0, execute naive multiplication algorithm
     *  algo = 1, fft_based multiplication
     *  the mean is calculated on number differents array of polynom coefficients
     */

    int *p1, *p2;
    double val = 0;
  
    for(int i = 0;i<number;i++) {
        p1 = random_polynom(size,0,100);
        p2 = random_polynom(size,0,100);
        val += measure_execution_time(p1,p2,size,size,algo);
    }

    if (p1) free(p1);
    if (p2) free(p2);
    
    return (double) val / number;
}

void measure_execution_time_mean_algos(int size, int number, double * t_naive, double * t_fft)
{
    /*  retourne un tableau contenant la moyenne de chaque algo sur number instances du temps d'éxécution moyen pour 
     *  la multiplication de deux mêmes polynômes. l'élément d'indice 0 correspond à l'algorithme naïf, 
     *  l'élément d'indice 1 correspond à l'algorithme fft
     */

    int *p1, *p2;
    // double * tab_res = malloc(sizeof(double[2]));
    double time_naive, time_fft = 0;
  
    for(int i = 0;i<number;i++) {
        p1 = random_polynom(size,0,100);
        p2 = random_polynom(size,0,100);
        time_naive += measure_execution_time(p1,p2,size,size,0);
        time_fft += measure_execution_time(p1,p2,size,size,1);
        free(p1);
        free(p2);
    }
    * t_naive = (double) time_naive / number;
    * t_fft = (double) time_fft / number;
}

int find_critical_size()
{
    /* find the size of polynom for which fft multiplication algorithm starts to be faster than naive multiplication */
    int max_n = 10;
    double t_naive,t_fft;

    printf("Looking for the size for which fft is faster....\n");
    do
    {
        measure_execution_time_mean_algos(max_n,20,&t_naive,&t_fft);
        max_n += 10;
        printf("n = %d exec_time_naive = %lf, exec_time_fft = %lf \n", max_n, t_naive,t_fft);

    } while (t_naive < t_fft);
    printf("Critical size found\n");

    return max_n;
}


void mean_execution_time_algos(int number, int N_max, int div, double ** tab_time_naive, double ** tab_time_fft)
{
    /*  fill the array tab_time and tab_sizes with the mean execution time for every sizes between 
     *  N_max / div and N_max for both algorithm
     */

    double t_naive,t_fft;
  
    for(int i = 1;i*N_max/div < N_max;i++) {
        measure_execution_time_mean_algos(i*N_max/div,number,&t_naive,&t_fft);
        * tab_time_naive[i-1] = t_naive;
        * tab_time_fft[i-1] = t_fft;

        // * tab_sizes[i-1] = i*N_max/div;
    }
   
}

// FILE *file = fopen("resultats_temps.csv", "w");
// if (file == NULL) {
//     perror("Erreur à l'ouverture du fichier");
//     return 1;
// }

// // Dans votre boucle ou fonction de mesure
// fprintf(file, "%d, %f\n", taille_polynome, temps_execution);

// fclose(file);