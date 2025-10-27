//Name: Yuvicka
//Roll no.: 1024240016
#include<iostream>
using namespace std;
// concatenate two strings
char str1[100], str2[100]; 
int main(){
    cout<<"Enter first string:";
    cin.getline(str1,100);
    cout <<"Enter second string:";
    cin.getline(str2,100);
    int i=0,j=0;
    while (str1[i]!='\0'){
        i++; 
    }
    while(str2[j]!='\0'){
        str1[i]=str2[j]; 
        i++; j++; 
    }
    str1[i]='\0'; 
    cout<<"Concatenated string is: "<<str1<<endl; 
    return 0; 
}


#include<iostream>
using namespace std;
//reverse of string
int main(){
    char str[100];
    cout << "Enter a string: ";
    cin.getline(str, 100); 
    int length=0;
    while(str[length]!= '\0') {
        length++; 
    }
    for(int i =length-1;i>=0;i--){
        cout << str[i]; 
    }
    cout << endl; 
    return 0; 
}


#include <iostream>
using namespace std;
//delete vowels from string
int main() {
    char str[100], result[100];
    int i = 0, j = 0;
    cout << "Enter a string: ";
    cin.getline(str, 100);  
    while (str[i] != '\0') {
        char ch = str[i];
        if (ch!='a' && ch!='e' && ch!='i' && ch!='o' && ch!='u' &&
            ch!='A' && ch!='E' && ch!='I' && ch!='O' && ch!='U') {
            result[j] = ch;
            j++;
        }
        i++;
    }
    result[j] = '\0'; 
    cout << "String after removing vowels: " << result << endl;
    return 0;
}



#include<iostream>
using namespace std;
// sot a string in alphabetical order
int main(){
    char str[100];
    cout << "Enter a string: ";
    cin.getline(str, 100); 
    int i, j;
    char temp;
    for (i = 0; str[i] != '\0'; i++) {
        for (j = i + 1; str[j] != '\0'; j++) {
            if (str[i] > str[j]) { 
                temp = str[i]; 
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
    cout << "Sorted string: " << str << endl; 
    return 0; 
}



#include<iostream>
using namespace std;
//uppercase to lowercase and vice versa
int main(){
    char str[100];
    cout << "Enter a string: ";
    cin.getline(str, 100); 
    for(int i=0;str[i] != '\0'; i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32; 
        } else if(str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32; 
        }
    }
    cout << "Modified string: " << str << endl; 
    return 0; 
}

