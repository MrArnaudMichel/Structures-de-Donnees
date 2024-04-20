cmake_minimum_required(VERSION 3.26)
project(P31 C)

set(CMAKE_C_STANDARD 11)

include_directories(p31)
include_directories(p31/algos)
include_directories(p31/containers)

add_executable(P31
        p31/tp_note/main.c
        p31/tp_note/algos/parentheses.c
        p31/tp_note/containers/stack.c
        p31/tp_note/containers/trie.c
        p31/tp_note/containers/vector.c
        p31/containers/linked_list.c
        p31/containers/hash_map.h
        p31/algos/bubble_sort.c
        p31/algos/insertion_sort.c
        p31/containers/hash_map.c
        p31/containers/stack.c
        p31/containers/heap.h
        p31/containers/heap.c)
