#include <stdio.h>

void print_array(int *arr, int n) {
	printf("array: ");
	for (int i = 0; i < n; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
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
			arr[k] = arr_l[i];
			i++;
		} else {
			arr[k] = arr_r[j];
			j++;
		}
		k++;
	}

	while (i < nl) {
		arr[k] = arr_l[i];
		i++;
		k++;
	}
	while (j < nr) {
		arr[k] = arr_r[j];
		j++;
		k++;
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

int main(void) {
	int arr[] = {5, 2, 6, 39, 11, 20, 9, 1, 6};
	size_t n = sizeof(arr) / sizeof(arr[0]);
	print_array(arr, n);
	merge_sort(arr, 0, n - 1);
	print_array(arr, n);
	return 0;
}
