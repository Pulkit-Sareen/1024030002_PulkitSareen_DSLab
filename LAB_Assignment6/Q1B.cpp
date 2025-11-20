#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

// Create node
Node* createNode(int data) {
    Node* n = new Node;
    n->data = data;
    n->next = nullptr;
    return n;
}

// Insert at beginning
void insertBeginning(int data) {
    Node* n = createNode(data);
    if (head == nullptr) {
        head = n;
        n->next = head;
        return;
    }

    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    n->next = head;
    temp->next = n;
    head = n;
}

// Insert at end
void insertEnd(int data) {
    Node* n = createNode(data);

    if (head == nullptr) {
        head = n;
        n->next = head;
        return;
    }

    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = n;
    n->next = head;
}

// Insert after a value
void insertAfter(int value, int data) {
    Node* temp = head;
    if (head == nullptr) return;

    do {
        if (temp->data == value) {
            Node* n = createNode(data);
            n->next = temp->next;
            temp->next = n;
            return;
        }
        temp = temp->next;
    } while (temp != head);
}

// Insert before a value
void insertBefore(int value, int data) {
    if (head == nullptr) return;

    Node *temp = head, *prev = nullptr;

    do {
        if (temp->data == value) {
            if (temp == head) {
                insertBeginning(data);
                return;
            }

            Node* n = createNode(data);
            prev->next = n;
            n->next = temp;
            return;
        }
        prev = temp;
        temp = temp->next;
    } while (temp != head);
}

// Delete a value
void deleteValue(int value) {
    if (head == nullptr) return;

    Node *temp = head, *prev = nullptr;

    do {
        if (temp->data == value) {
            if (temp == head) {
                Node* last = head;
                while (last->next != head) last = last->next;

                if (head == head->next) {
                    delete head;
                    head = nullptr;
                    return;
                }

                last->next = head->next;
                head = head->next;
                delete temp;
                return;
            }

            prev->next = temp->next;
            delete temp;
            return;
        }

        prev = temp;
        temp = temp->next;

    } while (temp != head);
}

// Search
void search(int value) {
    if (head == nullptr) return;

    int pos = 1;
    Node* temp = head;

    do {
        if (temp->data == value) {
            cout << "Found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);

    cout << "Not found.\n";
}

// Display
void display() {
    if (head == nullptr) return;

    Node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);

    cout << "(back to head)\n";
}

int main() {
    int choice, value, data;

    while (true) {
        cout << "\n--- CIRCULAR LINKED LIST MENU ---\n";
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
