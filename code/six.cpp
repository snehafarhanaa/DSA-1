#include <stdio.h>

void findFirstAndLast(int arr[], int n, int target, int *first, int *last) {
    *first = -1; // Initialize first occurrence
    *last = -1;  // Initialize last occurrence

    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            if (*first == -1) {
                *first = i; // Store the index of the first occurrence
            }
            *last = i; // Update the last occurrence index
        }
    }
}

int main() {
    int n, target;

    // Input array size and elements
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input target value
    printf("Enter the target value: ");
    scanf("%d", &target);

    int first, last;

    // Function call to find occurrences
    findFirstAndLast(arr, n, target, &first, &last);

    // Output results
    if (first == -1) {
        printf("Target value not found in the array.\n");
    } else {
        printf("First occurrence: %d\n", first);
        printf("Last occurrence: %d\n", last);
    }

    return 0;
}

