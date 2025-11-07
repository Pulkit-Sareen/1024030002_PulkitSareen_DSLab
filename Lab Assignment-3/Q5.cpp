#include <iostream>
#include <string>
#include <cmath>
using namespace std;

const int MAX = 100;
int stack[MAX];
int top = -1;


void push(int x) {
    if (top == MAX - 1) {
        cout << "Stack Overflow!" << endl;
    } else {
        stack[++top] = x;
    }
}

int pop() {
    if (top == -1) {
        cout << "Stack Underflow!" << endl;
        return -1;
    } else {
        return stack[top--];
    }
}


int evaluatePostfix(string exp) {
    for (int i = 0; i < exp.length(); i++) {
        char c = exp[i];

        
        if (isdigit(c)) {
            push(c - '0');   
        }
        
        else {
            int val2 = pop();
            int val1 = pop();

            switch (c) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
                case '^': push(pow(val1, val2)); break;
                default: 
                    cout << "Invalid operator: " << c << endl;
                    return -1;
            }
        }
    }
    return pop();  
}

int main() {
    string exp;
    cout << "Enter a postfix expression (single-digit operands): ";
    cin >> exp;

    cout << "Result = " << evaluatePostfix(exp) << endl;

    return 0;
}
