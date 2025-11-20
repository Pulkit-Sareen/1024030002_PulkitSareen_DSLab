#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* prev;
    Node* next;
};

Node* head = nullptr;

Node* createNode(char c) {
    Node* n = new Node;
    n->data = c;
    n->prev = nullptr;
    n->next = nullptr;
    return n;
}

void insertEnd(char c) {
    Node* n = createNode(c);
    if (head == nullptr) {
        head = n;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = n;
    n->prev = temp;
}

bool isPalindrome(Node* head) {
    if (head == nullptr) return true;

    Node* left = head;
    Node* right = head;


    while (right->next != nullptr)
        right = right->next;

    
    while (left != right && right->next != left) {
        if (left->data != right->data)
            return false;

        left = left->next;
        right = right->prev;
    }

    return true;
}

int main() {
    
    insertEnd('r');
    insertEnd('a');
    insertEnd('c');
    insertEnd('e');
    insertEnd('c');
    insertEnd('a');
    insertEnd('r');

    if (isPalindrome(head))
        cout << "Doubly Linked List is Palindrome\n";
    else
        cout << "Not a Palindrome\n";

    return 0;
}
