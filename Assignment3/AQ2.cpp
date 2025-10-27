//Name: Yuvicka
//Roll N.: 1024240016
#include <iostream>
using namespace std;
//Reverse a string using stack
int main() {
    string str;
    cout << "Enter a string to reverse: ";
    getline(cin, str);

    int n = str.length();
    char stack[100]; 
    int top = -1; 

    for (int i = 0; i < n; i++) {
        stack[++top] = str[i];
    }
    cout << "Reversed string: ";
    while (top != -1) {
        cout << stack[top--];
    }
    cout << endl;

    return 0;
}


