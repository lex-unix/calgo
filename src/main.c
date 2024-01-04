#include <sort.h>
#include <stdio.h>

void print_array(int *arr, int n) {
	printf("array: ");
	for (int i = 0; i < n; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main(void) {
	int arr[] = {5, 2, 6, 39, 11, 20, 9, 1, 6};
	size_t n = sizeof(arr) / sizeof(arr[0]);

	print_array(arr, n);
	merge_sort(arr, 0, n - 1);
	print_array(arr, n);

	return 0;
}
