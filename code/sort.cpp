#include <stdio.h>

// Function to sort the array using Bubble Sort
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to calculate the median
float findMedian(int arr[], int size) {
    bubbleSort(arr, size); // Sort the array

    if (size % 2 == 0) {
        // If size is even, median is the average of two middle elements
        return (arr[size / 2 - 1] + arr[size / 2]) / 2.0;
    } else {
        // If size is odd, median is the middle element
        return arr[size / 2];
    }
}

int main() {
    int n;

    // Input array size
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    printf("Enter %d elements of the array:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Calculate and print the median
    float median = findMedian(arr, n);
    printf("The median is: %.2f\n", median);

    return 0;
}
