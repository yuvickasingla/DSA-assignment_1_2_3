// Name: Yuvicka
// Roll no.: 1024240016
#include <iostream>
using namespace std;
int findMissingLinear(int arr[], int size, int n) {
    int total = (n * (n + 1)) / 2;
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return total - sum;
}
int findMissingBinary(int arr[], int size) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == mid + 1) {
            low = mid + 1;   
        } else {
            high = mid - 1;  
        }
    }
    return low + 1; 
}

int main() {
    int maxSize = 100, arr[maxSize], n;
    cout << "Enter the value of n (range will be 1..n): ";
    cin >> n;
    int size = n - 1; 
    cout << "Enter " << size << " sorted elements (from 1..n with one missing):\n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    cout << "\nUsing Linear Method -> Missing number: "
         << findMissingLinear(arr, size, n) << endl;

    cout << "Using Binary Search -> Missing number: "
         << findMissingBinary(arr, size) << endl;

    return 0;
}
