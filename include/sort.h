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
void heap_sort(int arr[], int heap_size);

void quicksort(int arr[], int p, int r);
int quicksort_partion(int arr[], int p, int r);

void randomized_quicksort(int arr[], int p, int r);
int randomized_quicksort_partion(int arr[], int p, int r);

#endif
