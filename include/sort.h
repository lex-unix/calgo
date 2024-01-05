#ifndef SORT_H
#define SORT_H

void insertion_sort(int arr[], int n);

void merge_sort(int arr[], int p, int r);
void merge(int arr[], int p, int q, int r);

int heap_parent(int i);
int heap_left(int i);
int heap_right(int i);
void max_heapify(int arr[], int i, int heap_size);
void build_max_heap(int arr[], int heap_size);
void heapsort(int arr[], int heap_size);

#endif
