#include <stdio.h>

// Defining the insertion sort function with comparison and shift counts
void InsertionSort(int arr[], int n, int* comparisons, int* shifts) {
    /* defining k to hold key value iteratively */
    for (int k = 1; k < n; k++) {
        int key = arr[k];
        int p;
        /* Comparing with all predecessors starting with immediate predecessor till correct spot is found */
        (*comparisons)++;
        for (p = k - 1; p >= 0 && arr[p] > key; p--) {
            // Shifting all unsorted predecessor values one element ahead to place key in its correct spot
            arr[p + 1] = arr[p];
            (*shifts)++;
        }
        // Placing key value in the correct spot
        arr[p + 1] = key;
    }
}

void main() {
    int arr[] = {11, 13, 12, 5, 6};
    // n is the size of the array, however, each element of the array is an integer
    int n = sizeof(arr) / sizeof(int);
    int comparisons = 0;
    int shifts = 0;

    // Printing the initial array
    printf("Initial array: ");
    for (int i = 0; i <= n - 1; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sorting the array using Insertion Sort and counting comparisons and shifts
    InsertionSort(arr, n, &comparisons, &shifts);

    // Printing the sorted array
    printf("Sorted array: ");
    for (int i = 0; i <= n - 1; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nNumber of comparisons: %d\n", comparisons);
    printf("Number of shifts: %d\n", shifts);
}

