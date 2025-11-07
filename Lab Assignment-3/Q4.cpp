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

bool isEmpty() {
    return (top == -1);
}


int precedence(char c) {
    if (c == '^') return 3;
    else if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    else return -1;
}


string infixToPostfix(string exp) {
    string result = "";

    for (int i = 0; i < exp.length(); i++) {
        char c = exp[i];


        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            result += c;
        }
        
        else if (c == '(') {
            push(c);
        }
        
        else if (c == ')') {
            while (!isEmpty() && peek() != '(') {
                result += pop();
            }
            pop(); 
        }
        
        else {
            while (!isEmpty() && precedence(peek()) >= precedence(c)) {
                result += pop();
            }
            push(c);
        }
    }

    
    while (!isEmpty()) {
        result += pop();
    }

    return result;
}

int main() {
    string exp;
    cout << "Enter an infix expression: ";
    cin >> exp;

    cout << "Postfix expression: " << infixToPostfix(exp) << endl;

    return 0;
}
