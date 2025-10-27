//Name: Yuvicka
//Roll no.: 1024240016
#include <iostream>
using namespace std;

int main() {
    int n, choice;
    cout << "Enter size of square matrix (n): ";
    cin >> n;

    int mat[20][20]; 
    int row[100], col[100], val[100]; // sparse representation
    int k = 1; 
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            mat[i][j] = 0;
    cout << "\nChoose Matrix Type:\n";
    cout << "1. Diagonal\n2. Tri-diagonal\n3. Lower Triangular\n4. Upper Triangular\n5. Symmetric\n";
    cin >> choice;
    if (choice == 1) {
        cout << "Enter " << n << " diagonal elements:\n";
        for (int i = 0; i < n; i++) {
            cin >> mat[i][i];
        }
    }
    else if (choice == 2) {
        cout << "Enter elements for tri-diagonal matrix:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i==j || i==j+1 || i==j-1) cin >> mat[i][j];
            }
        }
    }
    else if (choice == 3) {
        cout << "Enter elements for lower triangular matrix:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) cin >> mat[i][j];
        }
    }
    else if (choice == 4) {
        cout << "Enter elements for upper triangular matrix:\n";
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) cin >> mat[i][j];
        }
    }
    else if (choice == 5) {
        cout << "Enter elements for symmetric matrix (lower half incl. diagonal):\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                cin >> mat[i][j];
                mat[j][i] = mat[i][j]; 
            }
        }
    }
    else {
        cout << "Invalid choice!\n";
        return 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] != 0) {
                row[k] = i;
                col[k] = j;
                val[k] = mat[i][j];
                k++;
            }
        }
    }
    row[0] = n;
    col[0] = n;
    val[0] = k-1; 
    cout << "\nSparse Representation (Row Col Val):\n";
    for (int i = 0; i <= val[0]; i++) {
        cout << row[i] << "   " << col[i] << "   " << val[i] << endl;
    }
    cout << "\nReconstructed Matrix:\n";
    int idx = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (idx <= val[0] && row[idx] == i && col[idx] == j) {
                cout << val[idx] << " ";
                idx++;
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
    return 0;
}
