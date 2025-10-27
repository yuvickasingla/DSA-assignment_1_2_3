// Student ID: 1024240016
 // Assignment Question 4 Solution
#include<iostream>
using namespace std;
//reverse the array
int main(){
    int size;
    cout << "Enter size of array: ";
    cin >> size; // Input the size of the array

    int arr[size];
    cout << "Enter elements of array: ";
    for(int i = 0; i < size; i++){
        cin >> arr[i]; // Input elements into the array
    }

    for(int  i=0;i<size/2;i++){
        int temp=arr[i]; 
        arr[i]=arr[size-i-1]; 
        arr[size-i-1]=temp; 
    }
    cout << "Reversed array: ";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " "; // Output the reversed array
    }   
    cout << endl; 
    return 0; 
}




#include <iostream>
using namespace std;

#include<iostream>
using namespace std;
// Matrix multiplication
int main() {
    int A[10][10], B[10][10], C[10][10];
    int m, n, p, q;

    cout << "Enter rows and cols of Matrix A: ";
    cin >> m >> n;

    cout << "Enter rows and cols of Matrix B: ";
    cin >> p >> q;

    if(n != p) {
        cout << "Matrix multiplication not possible!" << endl;
        return 0;
    }

    cout << "Enter elements of Matrix A:" << endl;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Enter elements of Matrix B:" << endl;
    for(int i=0; i<p; i++) {
        for(int j=0; j<q; j++) {
            cin >> B[i][j];
        }
    }

    // Initialize result matrix to 0
    for(int i=0; i<m; i++) {
        for(int j=0; j<q; j++) {
            C[i][j] = 0;
        }
    }

    // Multiply matrices
    for(int i=0; i<m; i++) {
        for(int j=0; j<q; j++) {
            for(int k=0; k<n; k++) {
                C[i][j] = C[i][j] + (A[i][k] * B[k][j]);
            }
        }
    }

    cout << "Resultant Matrix (A x B):" << endl;
    for(int i=0; i<m; i++) {
        for(int j=0; j<q; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}




#include <iostream>
using namespace std;
//transpose of a matrix
int main() {
    int A[10][10], T[10][10];
    int m, n;

    cout << "Enter rows and cols of Matrix: ";
    cin >> m >> n;

    cout << "Enter elements of Matrix:" << endl;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin >> A[i][j];
        }
    }

    // Transpose logic (swap rows & cols)
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            T[j][i] = A[i][j];
        }
    }

    cout << "Transpose of Matrix:" << endl;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout << T[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

