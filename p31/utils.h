#pragma once

#include <sys/time.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

/*************************************************************************/
// timeval
/*************************************************************************/

void timeval_sub(struct timeval const *a, struct timeval const *b, struct timeval *result);

/*************************************************************************/
// int
/*************************************************************************/

size_t compare(void const *a, void const *b);

int rand_int_between(int min, int max);

typedef struct rectangle {
    double width;
    double height;
}rectangle;

int compare_int(void const *a, void const *b);

size_t compare_rectangle_area(void const *a, void const *b);

size_t compare_rectangle_perimeter(void const *a, void const *b);

uint32_t str_hash(char const *str);