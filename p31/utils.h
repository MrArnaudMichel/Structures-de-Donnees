#pragma once

#include <sys/time.h>

/*************************************************************************/
// timeval
/*************************************************************************/

void timeval_sub(struct timeval const *a, struct timeval const *b, struct timeval *result);

/*************************************************************************/
// int
/*************************************************************************/

int rand_int_between(int min, int max);
