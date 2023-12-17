#include "../include/polynom.h"

/* AUTHORS : TAN Philippe
             GOGRITCHIANI Lasha
             CHEN Virginie
*/

int *naive_algo(int *p1, int *p2, int len1, int len2)
{
    /*Returns an array which contains the result of the multiplication of two polynoms using naive algorithm*/

    int i, j;

    int *p3 = (int *)calloc(len1 + len2 - 1, sizeof(int));
    if (p3 == NULL)
    {
        perror("Erreur mémoire non allouée pour naive_algo! \n");
        exit(1);
    }

    for (i = 0; i < len1; i++)
    {
        for (j = 0; j < len2; j++)
        {
            p3[i + j] += p1[i] * p2[j];
        }
    }
    return p3;
}

void print_polynom(int *p, int len)
{
    /*Display an array of integers representing a polynom*/

    int i;
    for (i = 0; i < len; i++)
    {
        if (p[i])
            printf("%d*X^%d ", p[i], i);
    }
    printf("\n");
}

int generate_random_real(int a, int b)
{
    /*Generate a random real between a and b*/

    return a + ((double)rand() / RAND_MAX) * (b - a);
}

int *random_polynom(int deg, int a, int b)
{
    /*Returns a polynom of degree deg-1 with random integers coefficients between a and b*/

    int *p = (int *)calloc(deg, sizeof(int));
    if (p == NULL){
        perror("Mémoire non allouée pour random_polynom \n");
        exit(1);
    }
    int i;

    for (i = 0; i < deg; i++)
    {
        p[i] = generate_random_real(a, b);
    }

    return p;
}
