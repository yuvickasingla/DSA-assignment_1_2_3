//Name: Yuvicka
//Roll N.: 1024240016
#include<iostream>
using namespace std;
// menu driven program to perform operatons on a stack
int main(){
    int stack[100], top = -1, choice, value, size = 100;
    while(true){
        cout<<"Stack Operations Menu:\n";
        cout<<"1. Push\n";
        cout<<"2. Pop\n";
        cout<<"3. Display\n";
        cout<<"4.Peek\n";
        cout<<"5. check is Empty\n";
        cout<<"6. check is Full\n";
        cout<<"7. Exit\n";
        cout<<"Enter your choice: ";
        cin>> choice;
        switch(choice){
        case 1:
            cout<<"Enter value to push: ";
            cin>> value;
            if(top >=size-1){
                cout<<"Stack Overflow! Cannot push " << value << endl;
            }else{
                top++;
                stack[top] = value;
                cout<<"Pushed onto stack"<< endl;
            }
            break;
        case 2:
            if(top ==-1){
                cout<<"Stack Underflow! Cannot pop"<< endl;
            }else{
                cout<<"Popped value: " << stack[top] << endl;
                top--;
            }
            break;
        case 3:
            if(top == -1){
                cout<<"Stack is Empty!"<<endl;
            }else{
                cout<<"Stack elements:";
                for(int i=top;i>=0;i--) {
                    cout<< stack[i] << " ";}
                }
                cout<<endl;  
            break;     
        case 4:
            if(top ==-1){
                cout<<"Stack is Empty!"<<endl;
            }else{
                cout<<"Top element is: " << stack[top] << endl;
            }
            break;
        case 5:
            if(top==-1){
                cout<<"Stack is Empty!"<<endl;
            }else{
                cout<<"Stack is not Empty!"<<endl;
            }
            break;
        case 6:
            if(top >= size - 1){
                cout<<"Stack is Full!"<<endl;
            }else{
                cout<<"Stack is not Full!"<<endl;
            }
            break;
        case 7:
            cout<<"Exiting program."<<endl;
            return 0;
        default:
            cout<<"Invalid choice! Please try again."<<endl;    
            
            }}
        
    return 0; 
}

