#include <bits/stdc++.h>
using namespace std;

linSearch(int a[], int n, int key, int result[], int temp)
{
    temp = 0;
    for (int i = 0; i < n; i++) {
         if (a[i] == key) {
            result[temp++] = i;
        }
        }
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

    int result[n];
    int temp;

    linSearch(a, n, key, result, temp);

    if (temp > 0) {
        cout << "The target " << key << " appears at indices: ";
        for (int i = 0; i < temp; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    } else {
        cout << key << " does not appear in the array." << endl;
    }


    return 0;
}

