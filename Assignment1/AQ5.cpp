// Student ID: 1024240016
 // Assignment Question 5 Solution
#include <iostream>
using namespace std;

int main() {
    int A[10][10];
    int m, n;

    cout << "Enter number of rows: ";
    cin >> m;
    cout << "Enter number of columns: ";
    cin >> n;

    cout << "Enter elements of the matrix:" << endl;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin >> A[i][j];
        }
    }

    // Sum of each row
    cout << "\nSum of each row:" << endl;
    for(int i=0; i<m; i++) {
        int rowSum = 0;
        for(int j=0; j<n; j++) {
            rowSum += A[i][j];
        }
        cout << "Row " << i+1 << " = " << rowSum << endl;
    }

    // Sum of each column
    cout << "\nSum of each column:" << endl;
    for(int j=0; j<n; j++) {
        int colSum = 0;
        for(int i=0; i<m; i++) {
            colSum += A[i][j];
        }
        cout << "Column " << j+1 << " = " << colSum << endl;
    }

    return 0;
}
