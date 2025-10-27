//Name: Yuvicka
//Roll N.: 1024240016
#include <iostream>
#include <string.h>
using namespace std;
const int MAX = 100;
char stackArr[MAX];
int top = -1;
void push(char ch) {
    if (top == MAX - 1) {
        cout << "Stack Overflow\n";
        return;
    }
    stackArr[++top] = ch;
}
char pop() {
    if (top == -1) {
        return '\0'; 
    }
    return stackArr[top--];
}
char peek() {
    if (top == -1) return '\0';
    return stackArr[top];
}
bool isEmpty() {
    return (top == -1);
}
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}
string infixToPostfix(string expr) {
    string result = "";

    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            result += ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (!isEmpty() && peek() != '(') {
                result += pop();
            }
            pop(); 
        }
        else {
            while (!isEmpty() && precedence(peek()) >= precedence(ch)) {
                result += pop();
            }
            push(ch);
        }
    }
    while (!isEmpty()) {
        result += pop();
    }

    return result;
}

int main() {
    string expr1 = "(a+b)*c";
    string expr2 = "a+b*(c^d-e)^(f+g*h)-i";

    cout << "Infix: " << expr1 << " -> Postfix: " << infixToPostfix(expr1) << endl;
    cout << "Infix: " << expr2 << " -> Postfix: " << infixToPostfix(expr2) << endl;

    return 0;
}
