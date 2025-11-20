#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = nullptr;

// Create node
Node* createNode(int data) {
    Node* n = new Node;
    n->data = data;
    n->prev = nullptr;
    n->next = nullptr;
    return n;
}

// Insert at beginning
void insertBeginning(int data) {
    Node* n = createNode(data);
    if (head != nullptr) head->prev = n;
    n->next = head;
    head = n;
}

// Insert at end
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
    n->prev = temp;
}

// Insert before a value
void insertBefore(int value, int data) {
    if (head == nullptr) return;

    Node* temp = head;

    if (head->data == value) {
        insertBeginning(data);
        return;
    }

    while (temp != nullptr && temp->data != value)
        temp = temp->next;

    if (temp == nullptr) return;

    Node* n = createNode(data);
    n->next = temp;
    n->prev = temp->prev;
    temp->prev->next = n;
    temp->prev = n;
}

// Insert after a value
void insertAfter(int value, int data) {
    Node* temp = head;
    while (temp != nullptr && temp->data != value)
        temp = temp->next;

    if (temp == nullptr) return;

    Node* n = createNode(data);
    n->next = temp->next;
    n->prev = temp;

    if (temp->next != nullptr)
        temp->next->prev = n;

    temp->next = n;
}

// Delete a node by value
void deleteValue(int value) {
    if (head == nullptr) return;

    Node* temp = head;

    while (temp != nullptr && temp->data != value)
        temp = temp->next;

    if (temp == nullptr) return;

    if (temp->prev != nullptr)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != nullptr)
        temp->next->prev = temp->prev;

    delete temp;
}

// Search
void search(int value) {
    Node* temp = head;
    int pos = 1;

    while (temp != nullptr) {
        if (temp->data == value) {
            cout << "Found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }

    cout << "Not found.\n";
}

// Display
void display() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    int choice, value, data;

    while (true) {
        cout << "\n--- DOUBLY LINKED LIST MENU ---\n";
        cout << "1. Insert Beginning\n2. Insert End\n3. Insert Before\n4. Insert After\n";
        cout << "5. Delete Value\n6. Search\n7. Display\n8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cin >> data;
                insertBeginning(data);
                break;
            case 2:
                cin >> data;
                insertEnd(data);
                break;
            case 3:
                cin >> data >> value;
                insertBefore(value, data);
                break;
            case 4:
                cin >> data >> value;
                insertAfter(value, data);
                break;
            case 5:
                cin >> value;
                deleteValue(value);
                break;
            case 6:
                cin >> value;
                search(value);
                break;
            case 7:
                display();
                break;
            case 8:
                return 0;
        }
    }
}
