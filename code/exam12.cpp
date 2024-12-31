#include <iostream>

using namespace std;

void bubbleSort(int arr[],int n) {
    for(int i=0;i<n-1;i+=2) {
        for(int j=0;j<n-i-1;j+=2) {
            if(arr[j]<arr[j+2]) {
                swap(arr[j],arr[j+2]);
            }
        }
    }
    for(int i=1;i<n-1;i+=2) {
        for(int j=1;j<n-i-1;j+=2) {
            if(arr[j]>arr[j+2]) {
                swap(arr[j],arr[j+2]);
            }
        }
    }
}
void normalBubbleSort(int arr[],int n) {
    for(int i=0;i<n-1;i++) {
        for(int j=0;j<n-i-1;j++) {
            if(arr[j]>arr[j+1]) {
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

int binarySearch(int arr[],int n,int key) {
    // normalBubbleSort(arr,n);
    if(key<=0) return 1;
    int low = 0;
    int high = n-1;
    int mid,ans=-1;

    while(low<=high) {
        mid = (low+high)/2;

        cout<<"mid-> "<<mid<<endl;

        if(mid%2 == 0 ) mid++;

        if(arr[mid]==key) {
            ans = mid;
            break;
        }
        else if(arr[mid]<key) {
            low = mid+2;
        }
        else if(arr[mid]>key) {
            high = mid-1;
        }

        // cout<<" low-> "<<low<<" high-> "<<high<<endl;
    }
    if(ans==-1) {
    if(low>=n) return high-1;
    else return low;
    }
    return ans;
}

int main() {
    int arr[9] = {10,3,15,8,23,7,6,1,9};

    for(int i=0; i<9 ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    bubbleSort(arr,9);
    cout << "Sorted Array: ";
    for(int i=0; i<9 ; i++){
        cout << arr[i] << " ";
    }
    cout<<endl;
    int in = binarySearch(arr, 9, 1);
    cout << endl << "Index number: " << in;
}
