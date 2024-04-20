//
// Created by arnaud on 06/12/23.
//

#ifndef HANOI_TOWERS_H
#define HANOI_TOWERS_H

#include "stack.h"

void hanoi_towers(int n, stack *start, stack *inter, stack *end);
void move_disk(stack *source, stack *destination);


#endif //HANOI_TOWERS_H
