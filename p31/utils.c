#include "utils.h"

#include <stdlib.h>

/*************************************************************************/
// int
/*************************************************************************/

int rand_int_between(int min, int max)
{
    int range = (max - min);
    return min + (rand() % range);
}
