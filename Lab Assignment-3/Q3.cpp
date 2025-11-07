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
        return '\0'; 
    } else {
        return stack[top--];
    }
}


char peek() {
    if (top == -1) return '\0';
    return stack[top];
}


bool isBalanced(string exp) {
    for (int i = 0; i < exp.length(); i++) {
        char c = exp[i];

        if (c == '(' || c == '{' || c == '[') {
            push(c);
        } 
        else if (c == ')' || c == '}' || c == ']') {
            if (top == -1) return false; 

            char topChar = pop();

            if ((c == ')' && topChar != '(') ||
                (c == '}' && topChar != '{') ||
                (c == ']' && topChar != '[')) {
                return false;
            }
        }
    }

    return (top == -1);  
}

int main() {
    string expr;
    cout << "Enter an expression: ";
    cin >> expr;

    if (isBalanced(expr)) {
        cout << "Balanced Expression" << endl;
    } else {
        cout << "Not Balanced Expression" << endl;
    }

    return 0;
}
