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

size_t compare(void const *a, void const *b)
{
    return *(int *)a - *(int *)b;
}

int compare_int(void const *a, void const *b){
    return *(int *)a - *(int *)b;
}

size_t compare_rectangle_area(void const *a, void const *b){
    return ((rectangle *)a)->width * ((rectangle *)a)->height == ((rectangle *)b)->width * ((rectangle *)b)->height;
}

size_t compare_rectangle_perimeter(void const *a, void const *b){
    return 2 * (((rectangle *)a)->width + ((rectangle *)a)->height) == 2 * (((rectangle *)b)->width + ((rectangle *)b)->height);
}

uint32_t str_hash(char const *str)
{
    uint32_t h = 0;
    for (char const *p = str; *p != '\0'; p++)
    {
        h = (h << 4) + (uint32_t)(*p);
        uint32_t g = h & 0xF0000000L;
        if (g != 0)
            h = h ^ (g >> 24);
        h = h & ~g;
    }
    return h;
}