#ifndef _SORT_H_
#define _SORT_H_

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define swap(x, y) \
 {                 \
  int temp = x;    \
  x = y;           \
  y = temp;        \
 }

void print_array(const int *array, size_t size);

void heapify(int *array, size_t size, size_t calcsize, int idx);
void heap_sort(int *array, size_t size);

#endif
