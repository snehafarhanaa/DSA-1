#include <stdio.h>
int findKey(int a[], int n, int key) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == key) {
            printf("Key found at index %d\n", i);
            found = 1;
            found++;
        }
    }
    if (found==0){
        printf("Not Found\n");
    }

}

int main() {
    int n;
    printf("size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int key;
    printf("Enter key: ");
    scanf("%d", &key);

    findKey(arr, n, key);

    return 0;
}
