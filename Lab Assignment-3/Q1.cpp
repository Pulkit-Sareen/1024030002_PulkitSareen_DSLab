#include <iostream>
using namespace std;

const int MAX = 5;  

int stack[MAX];
int top = -1;

void push(int x) {
    if (top == MAX - 1) {
        cout << "Stack Overflow! Cannot push " << x << endl;
    } else {
        stack[++top] = x;
        cout << x << " pushed into stack." << endl;
    }
}


void pop() {
    if (top == -1) {
        cout << "Stack Underflow! Nothing to pop." << endl;
    } else {
        cout << stack[top--] << " popped from stack." << endl;
    }
}


void peek() {
    if (top == -1) {
        cout << "Stack is empty!" << endl;
    } else {
        cout << "Top element is: " << stack[top] << endl;
    }
}


bool isEmpty() {
    return (top == -1);
}


bool isFull() {
    return (top == MAX - 1);
}


void display() {
    if (isEmpty()) {
        cout << "Stack is empty!" << endl;
    } else {
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int choice, value;

    do {
        cout << "\n--- Stack Menu ---" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Check if Empty" << endl;
        cout << "5. Check if Full" << endl;
        cout << "6. Display" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            if (isEmpty())
                cout << "Stack is Empty" << endl;
            else
                cout << "Stack is not Empty" << endl;
            break;
        case 5:
            if (isFull())
                cout << "Stack is Full" << endl;
            else
                cout << "Stack is not Full" << endl;
            break;
        case 6:
            display();
            break;
        case 7:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
