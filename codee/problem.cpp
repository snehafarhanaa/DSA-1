// linear search
#include <bits/stdc++.h>
using namespace std;

void linSearch(int a[], int n, int key, int resultt[], int &temp) {
    temp = 0; // Initialize temp to 0
    for (int i = 0; i < n; i++) {
        if (a[i] == key) {
            resultt[temp++] = i; // Store the index in resultt and increment temp
        }
    }
}

int findFirstGreater(int a[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (a[i] > key) {
            return a[i];
        }
    }
    return -1; // Return -1 if no element is greater than the target
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

    int resultt[n];
    int temp;

    linSearch(a, n, key, resultt, temp);

    if (temp > 0) {
        cout << "The target " << key << " appears at indices: ";
        for (int i = 0; i < temp; i++) {
            cout << resultt[i] << " ";
        }
        cout << endl;
    } else {
        cout << key << " does not appear in the array." << endl;
    }

    int result = findFirstGreater(a, n, key);
    if (result != -1) {
        cout << "The first element greater than the target is: " << result << endl;
    } else {
        cout << "No element is greater than the target." << endl;
    }
    return 0;
}

