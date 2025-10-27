//Name: Yuvicka
//Roll no.: 1024240016
#include <iostream>
using namespace std;
// linear and binary search
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; 
        }
    }
    return -1; 
}
int binarySearch(int arr[],int size,int target){
    int low=0, high=size-1;
    while(low<=high){
        int mid=(low+high)/2;
        if( arr[mid]==target){
            return mid;
        } else if(arr[mid]<target){
            low=mid+1;
        }else{
            high=mid-1;
        }

    }
    return -1;
}
int main(){
    int size;
    cout << "Enter the number of elements in the array: ";
    cin >> size; 
    int arr[size]; 
    cout << "Enter the sorted elements of the array:\n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i]; 
    }
    int target;
    cout << "Enter the element to search: ";
    cin >> target; 

    int linearResult = linearSearch(arr, size, target);
    if (linearResult != -1) {
        cout << "Element found at index (Linear Search): " << linearResult << endl;
    } else {
        cout << "Element not found (Linear Search)" << endl;
    }
    int binaryResult = binarySearch(arr, size, target);
    if (binaryResult != -1) {
        cout << "Element found at index (Binary Search): " << binaryResult << endl;
    } else {
        cout << "Element not found (Binary Search)" << endl;
    }
    return 0; 
}
