#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;   
char stack[MAX];
int top = -1;


void push(char c) {
    if (top == MAX - 1) {
        cout << "Stack Overflow!" << endl;
    } else {
        stack[++top] = c;
    }
}


char pop() {
    if (top == -1) {
        cout << "Stack Underflow!" << endl;
        return '\0';
    } else {
        return stack[top--];
    }
}

int main() {
    string str, reversed = "";
    cout << "Enter a string: ";
    cin >> str;

    
    for (int i = 0; i < str.length(); i++) {
        push(str[i]);
    }

    
    while (top != -1) {
        reversed += pop();
    }

    cout << "Reversed string: " << reversed << endl;

    return 0;
}
