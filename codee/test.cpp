#include <iostream>
#include <string.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of strings: ";
    cin >> n;

    // Declare an array of strings (char arrays)
    char arr[n][100];

    // Input the strings
    cout << "Enter the strings:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Sorting strings based on their length
    char temp[100];
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            int len_i = strlen(arr[i]);
            int len_j = strlen(arr[j]);

            if (len_i > len_j) {
                // Swap strings if length of arr[i] > arr[j]
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }

    // Output the sorted strings
    cout << "Strings sorted by length:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}
