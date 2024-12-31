#include <iostream>
using namespace std;

// Function to sort the array using Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap the elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
/*
// Function to find the kth smallest element
int findKthSmallest(int arr[], int n, int k) {
    bubbleSort(arr, n); // Sort the array
    return arr[k - 1];  // Return the kth smallest element
}*/

float findMedian(int arr[], int size) {
    // Sort the array
    bubbleSort(arr, size);

    // Calculate the median
    if (size % 2 != 0) {
        return arr[size / 2]; // Odd size, middle element
    } else {
        int mid1 = size / 2;
        int mid2 = mid1 - 1;
        return (arr[mid1] + arr[mid2]) / 2.0; // Even size, average of middle elements
    }
}
int main() {
    int n, k;

    // Input the size of the array
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];

    // Input the array elements
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Input k
   /* cout << "Enter the value of k: ";
    cin >> k;

    // Check if k is valid
    if (k > 0 && k <= n) {
        // Find and print the kth smallest element
        int kthSmallest = findKthSmallest(arr, n, k);
        cout << "The " << k << "th smallest element is: " << kthSmallest << endl;
    } else {
        cout << "Invalid value of k!" << endl;
    }*/

    float median = findMedian(arr, n);
    cout << "The median is: " << median << endl;

    return 0;
}

