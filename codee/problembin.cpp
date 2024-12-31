#include <iostream>
using namespace std;

// Function to perform binary search
int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // To prevent overflow

        // Check if target is at mid
        if (arr[mid] == target) {
            return mid;
        }

        // If target is greater, ignore the left half
        if (arr[mid] < target) {
            left = mid + 1;
        }
        // If target is smaller, ignore the right half
        else {
            right = mid - 1;
        }
    }

    // Target is not present in the array
    return -1;
}
int binarySearchDescending(int arr[], int size, int target) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // To avoid overflow

        if (arr[mid] == target) {
            return mid; // Target found, return its index
        } else if (arr[mid] < target) {
            right = mid - 1; // Search in the left half
        } else {
            left = mid + 1; // Search in the right half
        }
    }

    return -1; // Target not found
}
// Function to find the first or last occurrence of the target
int findPosition(int arr[], int n, int target, bool findFirst) {
    int low = 0, high = n - 1, result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            result = mid;
            if (findFirst) {
                high = mid - 1; // Move left to find earlier occurrence
            } else {
                low = mid + 1; // Move right to find later occurrence
            }
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}
// Function to find the index where the target should be inserted
int findInsertIndex(int arr[], int size, int target) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // Target found, return its index
        } else if (arr[mid] < target) {
            left = mid + 1; // Target is in the right half
        } else {
            right = mid - 1; // Target is in the left half
        }
    }

    return left; // Return the position where the target should be inserted
}
    // Function to count occurrences of the target using binary search
    int countOccurrences(int arr[], int n, int target) {
    int low = 0, high = n - 1, result = 0;
    // Binary search for the first occurrence of the target
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            // Count occurrences by expanding to both sides
            result = 1;
            int left = mid - 1;
            int right = mid + 1;

            // Check left side
            while (left >= 0 && arr[left] == target) {
                result++;
                left--;
            }
            // Check right side
            while (right < n && arr[right] == target) {
                result++;
                right++;
            }
            break;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return result;
}

int main() {
    int n;
    printf("Enter size: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int target;

    cout << "Enter the target value: ";
    cin >> target;

    //int result = binarySearch(arr, n, target);
    //int result = binarySearchDescending(arr, n, target);
    //int first = findPosition(arr, n, target, true);
    //int last = findPosition(arr, n, target, false);

    /*if (result != -1) {
        cout << "Target found at index " << result << endl;
    } else {
        cout << "Target not found in the array." << endl;
    }
    if (first == -1) {
        cout << "Target not found: (-1, -1)" << endl;
    } else {
        cout << "First position: " << first << ", Last position: " << last << endl;
    }
    int index = findInsertIndex(arr, n, target);
    cout << "The target should be inserted at index: " << index << endl;*/
    int count = countOccurrences(arr, n, target);
    if (count > 0) {
        cout << "The target value " << target << " occurs " << count << " times in the array." << endl;
    } else {
        cout << "The target value " << target << " does not exist in the array." << endl;
    }



    return 0;
}

