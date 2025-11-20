#include <iostream>
using namespace std;


struct DLLNode {
    int data;
    DLLNode* prev;
    DLLNode* next;
};

DLLNode* dllHead = nullptr;

DLLNode* createDLLNode(int data) {
    DLLNode* n = new DLLNode;
    n->data = data;
    n->prev = nullptr;
    n->next = nullptr;
    return n;
}

void insertEndDLL(int data) {
    DLLNode* n = createDLLNode(data);
    if (dllHead == nullptr) {
        dllHead = n;
        return;
    }
    DLLNode* temp = dllHead;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = n;
    n->prev = temp;
}

int sizeDLL(DLLNode* head) {
    int count = 0;
    DLLNode* temp = head;

    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}



struct CLLNode {
    int data;
    CLLNode* next;
};

CLLNode* cllHead = nullptr;

CLLNode* createCLLNode(int data) {
    CLLNode* n = new CLLNode;
    n->data = data;
    n->next = nullptr;
    return n;
}

void insertEndCLL(int data) {
    CLLNode* n = createCLLNode(data);

    if (cllHead == nullptr) {
        cllHead = n;
        n->next = cllHead;
        return;
    }

    CLLNode* temp = cllHead;
    while (temp->next != cllHead)
        temp = temp->next;

    temp->next = n;
    n->next = cllHead;
}

int sizeCLL(CLLNode* head) {
    if (head == nullptr) return 0;

    int count = 0;
    CLLNode* temp = head;

    do {
        count++;
        temp = temp->next;
    } while (temp != head);

    return count;
}


// ---------------- MAIN ----------------
int main() {

    // DLL Example
    insertEndDLL(10);
    insertEndDLL(20);
    insertEndDLL(30);

    cout << "Size of Doubly Linked List = " << sizeDLL(dllHead) << endl;

    // CLL Example
    insertEndCLL(5);
    insertEndCLL(15);
    insertEndCLL(25);
    insertEndCLL(35);

    cout << "Size of Circular Linked List = " << sizeCLL(cllHead) << endl;

    return 0;
}
