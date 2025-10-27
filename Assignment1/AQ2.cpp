// Student ID: 1024240016
 // Assignment Question 2 Solution
#include <iostream>
using namespace std;
// to remove the duplicate elements from the array
void removeDuplicates(int arr[], int &size) {
    if (size <= 1) return; // No duplicates if size is 0 or 1

    int newSize = 1; // Start with the first element
    for (int i = 1; i < size; i++) {
        bool isDuplicate = false;
        for (int j = 0; j < newSize; j++) {
            if (arr[i] == arr[j]) {
                isDuplicate = true; // Found a duplicate
                break;
            }
        }
        if (!isDuplicate) {
            arr[newSize++] = arr[i]; // Add unique element to the new position
        }
    }
    size = newSize; // Update the size of the array
}
// Function to display the elements of the array
void displayArray(int arr[], int size) {
    cout << "Elements of the array are: "; 
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " "; // Display each element
    }
    cout << endl;
}   
int main() {
    const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int size = 0; // Current size of the array

    cout << "Enter number of elements (max " << MAX_SIZE << "): ";
    cin >> size;
    if (size > MAX_SIZE) {
        cout << "Size exceeds max limit. Try again.\n";
        return 1; // Exit if size is invalid
    }

    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    removeDuplicates(arr, size); // Remove duplicates from the array
    displayArray(arr, size); // Display the updated array

    return 0;
}
