#include "containers/vector_int.h"
#include "containers/vector.h"
#include "containers/linked_list.h"
#include "containers/stack.h"
#include "containers/hash_map.h"

#include "algos/bubble_sort.h"
#include "algos/insertion_sort.h"
#include "algos/hanoi_towers.h"

#include "utils.h"

#include <stdio.h>
#include <string.h>
#include <time.h>

/*************************************************************************/
// main
/*************************************************************************/


int main(int argc, char *argv[argc])
{
    // Create a hash_map instance
    hash_map h;
    hash_map_init(&h, 10, sizeof(int));

    // Insert some key-value pairs
    int value1 = 10;
    hash_map_insert(&h, "key1", &value1);

    int value2 = 20;
    hash_map_insert(&h, "key2", &value2);

    // Check if the keys exist
    bool contains1 = hash_map_contains(&h, "key1");
    bool contains2 = hash_map_contains(&h, "key2");
    bool contains3 = hash_map_contains(&h, "key3");

    // Print the results
    printf("Contains 'key1': %s\n", contains1 ? "true" : "false");
    printf("Contains 'key2': %s\n", contains2 ? "true" : "false");
    printf("Contains 'key3': %s\n", contains3 ? "true" : "false");

    // Clean up
    hash_map_free(&h);

    return EXIT_SUCCESS;
}