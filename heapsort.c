#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void heapify_num(int arr[], int n, int i){
	int largest = i; // Initialize largest as root
	int l = 2 * i + 1; // left = 2*i + 1
	int r = 2 * i + 2; // right = 2*i + 2
	int tmp;
	// If left child is larger than root
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest so far
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// If largest is not root
	if (largest != i) {
		tmp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = tmp;

		// Recursively heapify the affected sub-tree
		heapify_num(arr, n, largest);
	}
}

// main function to do heap sort
void heapSort_num(int arr[], int n){
	int tmp;
	// Build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify_num(arr, n, i);

	// One by one extract an element from heap
	for (int i = n - 1; i > 0; i--) {
		// Move current root to end
		tmp  = arr[0];
		arr[0] = arr[i];
		arr[i] = tmp;

		// call max heapify on the reduced heap
		heapify_num(arr, i, 0);
	}
}

void heapify_string(char arr[][101], int n, int i){
	int largest = i; // Initialize largest as root
	int l = 2 * i + 1; // left = 2*i + 1
	int r = 2 * i + 2; // right = 2*i + 2
	char tmp[101];
	// If left child is larger than root
	if (l < n && strcmp(arr[l], arr[largest]) > 0)
		largest = l;

	// If right child is larger than largest so far
	if (r < n && strcmp(arr[r], arr[largest]) > 0)
		largest = r;

	// If largest is not root
	if (largest != i) {
		strcpy(tmp, arr[i]);
		strcpy(arr[i], arr[largest]);
		strcpy(arr[largest], tmp);
		// Recursively heapify the affected sub-tree
		heapify_string(arr, n, largest);
	}
}

// main function to do heap sort
void heapSort_string(char arr[][101], int n){
	char tmp[101];
	// Build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify_string(arr, n, i);

	// One by one extract an element from heap
	for (int i = n - 1; i > 0; i--) {
		// Move current root to end
		strcpy(tmp, arr[0]);
		strcpy(arr[0], arr[i]);
		strcpy(arr[i], tmp);

		// call max heapify on the reduced heap
		heapify_string(arr, i, 0);
	}
}
