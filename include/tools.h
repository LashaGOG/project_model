#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h> // FOR MACOS ?
#include <time.h>

/* AUTHORS : TAN Philippe
             GOGRITCHIANI Lasha
             CHEN Virginie
*/

#ifndef TOOLS
#define TOOLS

double measure_execution_time(int *p1, int *p2, int n1, int n2, int algo);
int find_max_instance_size(int algo);

#endif // TOOLS