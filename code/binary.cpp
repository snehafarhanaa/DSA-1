#include <stdio.h>
int binarysearch(int a[], int n, int key) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (a[mid] == key)
            return mid;
        else if (a[mid] > key)
        low = mid + 1;

        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int n, key;
    printf("Enter size: ");
    scanf("%d", &n);
    int a[n];

    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Key:");
    scanf("%d", &key);

    int result = binarysearch(a, n, key);

    if (result != -1)
        printf("Key found at index %d\n", result);
    else
        printf("Key not found\n");

    return 0;
}
