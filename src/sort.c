#include <sort.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void exchange(int *arr, int i, int j) {
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

int randint(int a, int b) {
	srand(time(NULL));
	return (rand() % (b - a + 1)) + a;
}

void insertion_sort(int arr[], int n) {
	for (int i = 1; i < n; ++i) {
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

void merge_sort(int arr[], int p, int r) {
	if (p >= r) {
		return;
	}

	int q = (p + r) / 2;
	merge_sort(arr, p, q);
	merge_sort(arr, q + 1, r);
	merge(arr, p, q, r);
}

void merge(int arr[], int p, int q, int r) {
	int nl = q - p + 1;
	int nr = r - q;
	int arr_l[nl];
	int arr_r[nr];

	for (int i = 0; i < nl; ++i) {
		arr_l[i] = arr[p + i];
	}
	for (int i = 0; i < nr; ++i) {
		arr_r[i] = arr[q + 1 + i];
	}

	int i = 0;
	int j = 0;
	int k = p;

	while (i < nl && j < nr) {
		if (arr_l[i] <= arr_r[j]) {
			arr[k++] = arr_l[i++];
		} else {
			arr[k++] = arr_r[j++];
		}
	}

	while (i < nl) {
		arr[k++] = arr_l[i++];
	}
	while (j < nr) {
		arr[k++] = arr_r[j++];
	}
}

int heap_parent(int i) {
	return (i - 1) / 2;
}

int heap_left(int i) {
	return 2 * i + 1;
}

int heap_right(int i) {
	return 2 * i + 2;
}

void max_heapify(int *arr, int i, int heap_size) {
	int largest;
	int l = heap_left(i);
	int r = heap_right(i);

	if (l < heap_size && arr[l] > arr[i]) {
		largest = l;
	} else {
		largest = i;
	}

	if (r < heap_size && arr[r] > arr[largest]) {
		largest = r;
	}

	if (largest != i) {
		exchange(arr, i, largest);
		max_heapify(arr, largest, heap_size);
	}
}

void build_max_heap(int *arr, int heap_size) {
	for (int i = heap_size / 2; i >= 0; --i) {
		max_heapify(arr, i, heap_size);
	}
}

void heap_sort(int *arr, int heap_size) {
	build_max_heap(arr, heap_size);
	for (int i = heap_size - 1; i >= 1; --i) {
		exchange(arr, i, 0);
		heap_size--;
		max_heapify(arr, 0, heap_size);
	}
}

void quicksort(int *arr, int p, int r) {
	if (p >= r) {
		return;
	}
	int q = quicksort_partion(arr, p, r);
	quicksort(arr, p, q - 1);
	quicksort(arr, q + 1, r);
}

int quicksort_partion(int *arr, int p, int r) {
	int x = arr[r];
	int i = p - 1;
	for (int j = p; j < r; ++j) {
		if (arr[j] <= x) {
			++i;
			exchange(arr, i, j);
		}
	}
	exchange(arr, i + 1, r);
	return i + 1;
}

void randomized_quicksort(int *arr, int p, int r) {
	if (p >= r) {
		return;
	}

	int q = randomized_quicksort_partion(arr, p, r);
	randomized_quicksort(arr, p, q - 1);
	randomized_quicksort(arr, q + 1, r);
}

int randomized_quicksort_partion(int *arr, int p, int r) {
	int i = randint(p, r);
	exchange(arr, r, i);
	return quicksort_partion(arr, p, r);
}
