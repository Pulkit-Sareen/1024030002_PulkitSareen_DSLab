#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

Node* createNode(int data) {
    Node* n = new Node;
    n->data = data;
    n->next = nullptr;
    return n;
}

void insertEnd(int data) {
    Node* n = createNode(data);

    if (head == nullptr) {
        head = n;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = n;
}

bool isCircular(Node* head) {
    if (head == nullptr) return true;

    Node* temp = head->next;

    while (temp != nullptr && temp != head)
        temp = temp->next;

    return temp == head;
}

int main() {

    
    insertEnd(1);
    insertEnd(2);
    insertEnd(3);

    cout << "Is Circular? " << (isCircular(head) ? "Yes" : "No") << endl;

    
    Node* temp = head;
    while (temp->next != nullptr) temp = temp->next;
    temp->next = head;

    cout << "Is Circular? " << (isCircular(head) ? "Yes" : "No") << endl;

    return 0;
}
