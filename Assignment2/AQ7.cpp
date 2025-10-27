//Name: Yuvicka
//Roll no.: 1024240016
#include<iostream>
using namespace std;
// inversion count in an array
int countInversions(int arr[],int n){
    int count = 0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i] >arr[j]){
                count++; 
            }
        }
    }
}
int main(){
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n; 
    int arr[n]; 
    cout << "Enter the elements of the array:\n";
    for(int i=0;i<n;i++){
        cin >> arr[i]; 
    }
    int inversions = countInversions(arr, n); 
    cout << "Number of inversions in the array: " << inversions << endl;
}
