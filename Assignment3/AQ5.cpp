//Name: Yuvicka
//Roll N.: 1024240016
#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;

#define MAX 100
int stackArr[MAX];
int top = -1;

void push(int x) {
    if (top == MAX - 1) {
        cout << "Stack Overflow\n";
        return;
    }
    stackArr[++top] = x;
}
int pop() {
    if (top == -1) {
        cout << "Stack Underflow\n";
        return -1;
    }
    return stackArr[top--];
}
int power(int base, int exp) {
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

bool isDigit(char ch) {
    return (ch >= '0' && ch <= '9');
}

int evaluatePostfix(string expr) {
    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];
        if (isDigit(ch)) {
            push(ch - '0');   
        }
        else {
            int val2 = pop();
            int val1 = pop();

            switch (ch) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
                case '^': push(power((val1), (val2))); break;
            }
        }
    }
    return pop();
}

int main() {
    string expr1 = "23*54*+9-";   
    string expr2 = "231*+9-";     

    cout << "Postfix: " << expr1 << " -> Result: " << evaluatePostfix(expr1) << endl;
    cout << "Postfix: " << expr2 << " -> Result: " << evaluatePostfix(expr2) << endl;

    return 0;
}
