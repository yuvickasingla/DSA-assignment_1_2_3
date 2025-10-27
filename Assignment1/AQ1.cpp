// Student ID: 1024240016
 // Assignment Question 1 Solution
#include<iostream>
using namespace std;
const int MAX_SIZE = 100;
int arr[MAX_SIZE];
int size = 0; // Current size of the array
void createArray() {
    cout << "Enter number of elements (max " << MAX_SIZE << "): ";
    cin >> size;
    if (size > MAX_SIZE) {
        cout << "Size exceeds max limit. Try again.\n";
        size = 0;
        return;
    }
    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }
    cout << "Array created successfully.\n";
}
// Function to display the elements of the array
void displayArray() {
    cout << "Elements of the array are:";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " "; // Display each element
    }
    cout << endl;
}
// Function to find the display element in the array
void insertElement() {
    if(size < MAX_SIZE) {
        int pos,value;
        cout << "Enter the index to insert the element (0 to " << size << "): ";
        cin >> pos;
        if(pos < 0 || pos > size) {
            cout << "Invalid position!" << endl;
            return;
        }
        cout << "Enter the value to insert: ";
        cin >> value;
        for (int i = size; i > pos; i--) {
            arr[i] = arr[i - 1]; // Shift elements to the right
        }
        arr[pos] = value; // Insert the new element
        size++; // Increase the size of the array
        cout << "Element inserted successfully." << endl;
        
    } else {
        cout << "Array is full. Cannot insert more elements." << endl;
    }
}
void deleteElement() {
    if(size > 0) {
        int pos;
        cout << "Enter the position to delete the element (0 to " << size - 1 << "): ";
        cin >> pos;
        if(pos < 0 || pos >= size) {
            cout << "Invalid index!" << endl;
            return;
        }
        for (int i = pos; i < size - 1; i++) {
            arr[i] = arr[i + 1]; // Shift elements to the left
        }
        size--; // Decrease the size of the array
        cout << "Element deleted successfully." << endl;
    } else {
        cout << "Array is empty. Cannot delete elements." << endl;
    }
}
void searching(){
    if(size==0) {
        cout << "Array is empty. Cannot search for elements." << endl;
        return;}

    int key,found = 0;
    cout << "Enter the element to search: ";
    cin >> key;
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            cout << "Element found at index: " << i << endl;
            found = 1; // Element found
            break;
        }
    }
    if(!found) {
        cout << "Element not found in the array." << endl;
    }
}
int main() {
    int choice;
    do {
        cout << "\n——MENU——-\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: createArray(); break;
            case 2: displayArray(); break;
            case 3: insertElement(); break;
            case 4: deleteElement(); break;
            case 5: searching(); break;
            case 6: cout << "Exiting program.\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
