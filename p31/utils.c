#include "utils.h"

#include <stdlib.h>

/*************************************************************************/
// timeval
/*************************************************************************/

void timeval_sub(struct timeval const *a, struct timeval const *b, struct timeval *result)
{
    result->tv_sec = a->tv_sec - b->tv_sec;
    result->tv_usec = a->tv_usec - b->tv_usec;
    if (result->tv_usec < 0)
    {
        --result->tv_sec;
        result->tv_usec += 1000000;
    }
}

/*************************************************************************/
// int
/*************************************************************************/

int rand_int_between(int min, int max)
{
    int range = (max - min);
    return min + (rand() % range);
}
