#include <stdio.h>

// Function to sort an array in ascending order using Insertion Sort
void insertionSortAscending(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        // Move elements greater than key one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Function to sort an array in descending order using Insertion Sort
void insertionSortDescending(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        // Move elements smaller than key one position ahead
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n;

    // Input array size
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n], even[n], odd[n];
    int evenCount = 0, oddCount = 0;

    // Input array elements
    printf("Enter %d elements of the array:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);

        // Separate even-indexed and odd-indexed elements
        if (i % 2 == 0) {
            even[evenCount++] = arr[i];
        } else {
            odd[oddCount++] = arr[i];
        }
    }

    // Sort even-indexed elements in descending order
    insertionSortDescending(even, evenCount);

    // Sort odd-indexed elements in ascending order
    insertionSortAscending(odd, oddCount);

    // Merge sorted even and odd elements back into the original array
    int evenIndex = 0, oddIndex = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            arr[i] = even[evenIndex++];
        } else {
            arr[i] = odd[oddIndex++];
        }
    }

    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
