#include "../include/polynom.h"

/* AUTHORS : TAN Philippe
             GOGRITCHIANI Lasha
             CHEN Virginie
*/

int *naive_algo(int p1[], int p2[], int len1, int len2)
{
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

void print_polynom(int p[], int len)
{
    int i;
    printf("Le résulat de la multiplication des polynômes est : \n");
    for (i = 0; i < len; i++)
    {
        printf("%d*X^%d ", p[i], i);
    }
    printf("\n");
}

void delete_polynom(int p[])
{
    free(p);
}

int *get_pe(int *p, int n)
{
    /* return even terms of polynom p */
    int *pe = (int *)calloc(n / 2, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        pe[i] = p[2 * i];
    }
    return pe;
}
int *get_po(int *p, int n)
{
    /* return odd terms of polynom p */
    int *po = (int *)calloc(n / 2, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        po[i] = p[2 * i + 1];
    }
    return po;
}

// int* random_polynom(int size){
//     //Renvoie un polynôme de degré size random
// }
