//Name: Yuvicka
//Roll N.: 1024240016
#include<iostream>  
#include<string.h>
using namespace std;
// Function to check if brackets are balanced
bool isBalanced(string expression){
    char stack[100];
    int top = -1;
    for(int i=0;i<expression.length();i++){
        char ch=expression[i];
        if(ch=='{' || ch=='(' || ch=='['){
            stack[++top]=ch;
        }else if(ch=='}' || ch==')' || ch==']'){
            if(top==-1){
                return false;
            }
            char topChar=stack[top--];
            if((ch=='}' && topChar!='{') || (ch==')' && topChar!='(') || (ch==']' && topChar!='[')){
                return false;
            }
        }    
    }
    if (top == -1)
        return true;   
    else
        return false;  
}
int main() {
    string expr1 = "{[()()]}";
    string expr2 = "{[(])}";
    string expr3 = "((a-b)*c(d/f))";
    string expr4 = "(a+b";

    cout << expr1 << " -> " << (isBalanced(expr1) ? "Balanced" : "Not Balanced") << endl;
    cout << expr2 << " -> " << (isBalanced(expr2) ? "Balanced" : "Not Balanced") << endl;
    cout << expr3 << " -> " << (isBalanced(expr3) ? "Balanced" : "Not Balanced") << endl;
    cout << expr4 << " -> " << (isBalanced(expr4) ? "Balanced" : "Not Balanced") << endl;

    return 0;
}

