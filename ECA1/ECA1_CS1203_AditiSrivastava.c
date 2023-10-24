#include <stdio.h>
#include <stdlib.h>

//Allocating memory to make variable sized array of integers 
void generatePermutations(int n) {
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        arr[i] = i + 1;
    }

//Factorial: Multiplying previous value of totalPermutations by next value till n
    int totalPermutations = 1;
    for (int i = 1; i <= n; ++i) {
        totalPermutations *= i;
    }

    for (int i = 0; i < totalPermutations; ++i) {
        // Print current permutation
        for (int j = 0; j < n; ++j) {
            printf("%d", arr[j]);
            if (j < n - 1) {
                printf(",");
            }
        }
        printf("\n");

        // Generate next permutation using addition and subtraction
        int j = n - 2;
        while (j >= 0 && arr[j] > arr[j + 1]) {
            --j;
        }

        if (j < 0) {
            break;  // Last permutation reached
        }

        int k = n - 1;
        while (arr[j] > arr[k]) {
            --k;
        }

        // Swap arr[j] and arr[k] using addition and subtraction
        arr[j] = arr[j] + arr[k];
        arr[k] = arr[j] - arr[k];
        arr[j] = arr[j] - arr[k];

        // Reverse the elements after j using addition and subtraction
        int left = j + 1;
        int right = n - 1;
        while (left < right) {
            arr[left] = arr[left] + arr[right];
            arr[right] = arr[left] - arr[right];
            arr[left] = arr[left] - arr[right];
            ++left;
            --right;
        }
    }

    free(arr);
}

int main() {
    int n;
    printf("Enter the value of n (1 <= n <= 8): ");
    scanf("%d", &n);

    if (n < 1 || n > 8) {
        printf("Invalid input. n must be between 1 and 8.\n");
        return 1;
    }

    generatePermutations(n);
    return 0;
}
