//
// Created by musht on 09.02.2024.
//

#include <stdio.h>
#include "NonRecursiveMergeSort.h"

char *min_ptr(char *a_ptr, char *b_ptr) {
    if (a_ptr < b_ptr) {
        return a_ptr;
    } else {
        return b_ptr;
    }
}

void copy_bytes(char *src, char *dst, size_t count) {
    char *end = src + count;
    while (src < end) {
        *(dst++) = *(src++);
    }
}


void merge_sort(
        char *data_ptr,
        size_t elem_count,
        size_t elem_size,
        int (__cdecl *comp)(const void *, const void *),
        char *buffer
) {
    size_t cur_part_size = elem_size;
    size_t byte_count = elem_size * elem_count;
    size_t diff;
    char *left_ptr, *middle_ptr, *right_ptr, *end_ptr, *start_ptr;
    char *data_end_ptr = data_ptr + byte_count;
    char *cur_buffer;

    // while one part is smaller than whole array keep merging
    while (cur_part_size < byte_count) {
        left_ptr = data_ptr;
        while (left_ptr < data_end_ptr) {
            // define current parts
            start_ptr = left_ptr;
            right_ptr = left_ptr + cur_part_size;
            middle_ptr = right_ptr;
            end_ptr = min_ptr(right_ptr + cur_part_size, data_end_ptr);

            // merge using buffer
            cur_buffer = buffer;
            while (left_ptr < middle_ptr && right_ptr < end_ptr) {
                int comp_res = comp(left_ptr, right_ptr);
                if (comp_res <= 0) {
                    copy_bytes(left_ptr, cur_buffer, elem_size);
                    left_ptr += elem_size;
                } else {
                    copy_bytes(right_ptr, cur_buffer, elem_size);
                    right_ptr += elem_size;
                }
                cur_buffer += elem_size;
            }
            copy_bytes(left_ptr, cur_buffer, middle_ptr - left_ptr);

            diff = middle_ptr - left_ptr;
            copy_bytes(left_ptr, cur_buffer, diff);
            cur_buffer += diff;

            diff = end_ptr - right_ptr;
            copy_bytes(right_ptr, cur_buffer, diff);
            cur_buffer += diff;

            // copy sorted part back form buffer
            diff = end_ptr - start_ptr;
            copy_bytes(buffer, start_ptr, diff);

            // go to next parts to merge
            left_ptr = end_ptr;
        }
        // merge larger parts
        cur_part_size *= 2;
    }
}

int __cdecl compInts(const void *a_ptr, const void *b_ptr) {
    const int a = *(int *)a_ptr;
    const int b = *(int *)b_ptr;
    return (a > b) - (a < b);
}

void printIntArray(void *array, size_t size) {
    int *arr = (int *) array;
    size_t i;
    for (i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main () {
    const int size = 11;
    int arr[] = {3, 5, 6, -3, 0, 2, 15, 4, -2, 5, 6};
    int buffer[11];
    printIntArray(arr, size);
    merge_sort((char *) arr, size, sizeof(int), compInts, (char *) buffer);
    printIntArray(arr, size);
    return 0;
}
