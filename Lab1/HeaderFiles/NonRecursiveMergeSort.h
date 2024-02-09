//
// Created by musht on 09.02.2024.
//

#ifndef LAB1_CLION_NONRECURSIVEMERGESORT_H
#define LAB1_CLION_NONRECURSIVEMERGESORT_H

#include <stdint.h>

void merge_sort(
        char *data_ptr,
        size_t elem_count,
        size_t elem_size,
        int (__cdecl *comp)(const void *, const void*),
        char *buffer
);

#endif //LAB1_CLION_NONRECURSIVEMERGESORT_H
