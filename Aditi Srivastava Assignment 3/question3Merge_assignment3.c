#include <stdio.h>

// Declaring all my functions here:
// 1. Splitarr splits array recursively, middle element is identified at each step and used to further split the array
void splitarr(int arr[], int l, int r, int* comparisons, int* swaps);
// 2. Sort sorts and merges subarrays of the main array
void sort(int arr[], int l, int m, int r, int* comparisons, int* swaps);
// 3. Merge finally compares and merges subarrays into a complete and sorted array
void merge(int arrL[], int arrR[], int arr[], int l, int sizeL, int sizeR, int* comparisons, int* swaps);
// 4. Prints array
void printarray(int A[], int size);
// 5. Flooring to help make the merge function usable for subarrays with odd terms
int flooring(int dividend, int divisor);



int flooring(int dividend, int divisor) {
    if (dividend >= 0) {
        return dividend / divisor;
    } else {
        return (dividend - divisor + 1) / divisor;
    }
}

// Splitting array
void splitarr(int arr[], int l, int r, int* comparisons, int* swaps) {
    if (l < r) {
        int m = l + flooring(r - l, 2);

        // Splitting left sub-array using recursion
        splitarr(arr, l, m, comparisons, swaps);
        // Splitting right sub-array
        splitarr(arr, m + 1, r, comparisons, swaps);

        // Moving on to sorting and merging function
        sort(arr, l, m, r, comparisons, swaps);
    }
}

void sort(int arr[], int l, int m, int r, int* comparisons, int* swaps) {
    int sizeL = m - l + 1;
    int sizeR = r - m;
    int arrL[sizeL], arrR[sizeR];

    for (int i = 0; i < sizeL; i++)
        arrL[i] = arr[l + i];
    for (int j = 0; j < sizeR; j++)
        arrR[j] = arr[m + 1 + j];

    merge(arrL, arrR, arr, l, sizeL, sizeR, comparisons, swaps);
}

// Merging left and right subarrays into the main array
void merge(int arrL[], int arrR[], int arr[], int l, int sizeL, int sizeR, int* comparisons, int* swaps) {
    int i = 0;
    int j = 0;
    int k = l;

    // Place smaller element from the left, right arrays and progress i, j accordingly
    while (i < sizeL && j < sizeR) {
        (*comparisons)++;
        if (arrL[i] <= arrR[j]) {
            arr[k] = arrL[i];
            i++;
        } else {
            arr[k] = arrR[j];
            j++;
            (*swaps)++;
        }
        k++;
    }

    // Remaining elements of the left array placed into the array incrementally
    while (i < sizeL) {
        arr[k] = arrL[i];
        i++;
        k++;
        (*swaps)++;
    }

    // Same for the right
    while (j < sizeR) {
        arr[k] = arrR[j];
        j++;
        k++;
        (*swaps)++;
    }
}

// Printing array
void printarray(int A[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main() {
    int arr[] = {9, 8, 3, 4, 15, 6, 3, 5, 7, 8, 2};
    int l = 0;
    int arrsize = sizeof(arr) / sizeof(int);
    int r = arrsize - 1;
    int comparisons = 0;
    int swaps = 0;

    printf("Given array is \n");
    printarray(arr, arrsize);

    splitarr(arr, l, r, &comparisons, &swaps);

    printf("Sorted array is \n");
    printarray(arr, arrsize);

    printf("Number of comparisons: %d\n", comparisons);
    printf("Number of swaps: %d\n", swaps);

    return 0;
}


