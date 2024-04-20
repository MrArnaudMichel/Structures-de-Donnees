//
// Created by arnaud on 06/12/23.
//

#include "hanoi_towers.h"

void hanoi_towers(int n, stack *start, stack *inter, stack *end) {
    if (n == 0) {
        return;
    }
    hanoi_towers(n - 1, start, end, inter);
    int * value = malloc(sizeof(start->value_size));
    stack_pop(start, value);
    stack_push(end, value);
    hanoi_towers(n - 1, inter, start, end);
}