#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

void traversal(Node* head) {
    if (head == nullptr) {
        cout << endl;
        return;
    }
    cout << head->data << endl;
    traversal(head->next);
}

bool searchinginlinkedlist(Node* head, int search) {
    Node* curr = head;
    while (curr != nullptr) {
        if (curr->data == search) {
            return true;
        }
        curr = curr->next;
    }
    return false;
}

int lengthofSLL(Node* head) {
    int cnt = 0;
    Node* curr = head;
    while (curr != nullptr) {
        cnt++;
        curr = curr->next;
    }
    return cnt;
}

// ✅ Pass head by reference so changes reflect in main
void insertionatbegginginofSll(Node*& head, Node* newnode) {
    newnode->next = head;
    head = newnode;  // ✅ Fix this line
}

int main() {
    int n;
    cout << "Enter nodes: ";
    cin >> n;
    cout << endl;

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        Node* newnode = new Node(val);
        if (head == nullptr) {
            head = tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
    }

    int option;
    cout << "\n1. Print the Single Linked List\n2. Search an Element\n3. Length of SLL\n4. Insert at Beginning" << endl;
    cout << "Enter option: ";
    cin >> option;

    if (option == 1) {
        traversal(head);
    } else if (option == 2) {
        int search;
        cout << "Enter element to search: ";
        cin >> search;
        if (searchinginlinkedlist(head, search)) {
            cout << "Yes, element found" << endl;
        } else {
            cout << "No, not found" << endl;
        }
    } else if (option == 3) {
        int length = lengthofSLL(head);
        cout << "Length of Single Linked List: " << length << endl;
    } else if (option == 4) {
        int newval;
        cout << "Enter new value to insert at beginning: ";
        cin >> newval;
        Node* temp = new Node(newval); 
        insertionatbegginginofSll(head, temp); 
        traversal(head);
    } else {
        cout << "Invalid option!" << endl;
    }

    return 0;
}
