#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

void traversal(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

bool search(Node* head, int key) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == key) return true;
        temp = temp->next;
    }
    return false;
}

int length(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

void insertAtBeginning(Node*& head, Node* newnode) {
    newnode->next = head;
    head = newnode;
}

void insertAtEnd(Node*& head, Node* newnode) {
    if (head == nullptr) {
        head = newnode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newnode;
}

void insertAtPosition(Node*& head, Node* newnode, int pos) {
    if (pos <= 0) {
        cout << "Invalid position." << endl;
        return;
    }

    if (pos == 1) {
        newnode->next = head;
        head = newnode;
        return;
    }

    Node* temp = head;
    int count = 1;

    while (temp != nullptr && count < pos - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == nullptr) {
        cout << "Position out of bounds." << endl;
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

void deleteheadofsll(Node*&head){
    Node*temp=head;
    head=head->next;
    delete temp;
    
}
void deletespecificposofsll(Node*&head,int pos){
    Node*temp=head;
    int cnt=1;
    
    while(temp!=nullptr){
        cnt++;
        if(cnt==pos){
          Node*delnode=temp->next;
          temp->next=delnode->next;
          delete delnode;
        }
        temp=temp->next;
        
    }
}
void deleteatendofsll(Node*&head){
   Node* temp = head;
while (temp->next->next != nullptr) {
    temp = temp->next;
}
delete temp->next;
temp->next = nullptr;

}
int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter node values: ";
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
    cout << "\nMenu:\n";
    cout << "1. Print List\n";
    cout << "2. Search Element\n";
    cout << "3. Find Length\n";
    cout << "4. Insert at Beginning\n";
    cout << "5. Insert at End\n";
    cout << "6. Insert at Specific Position\n";
    cout<<"7. Deletion head of linkedlist\n";
    cout<<"8. Deletion at a Specific Position of sll\n";
     cout<<"9. Deletion at a end of sll\n";
    cout << "Enter your choice: ";
    cin >> option;

    if (option == 1) {
        traversal(head);
    } else if (option == 2) {
        int key;
        cout << "Enter value to search: ";
        cin >> key;
        cout << (search(head, key) ? "Found\n" : "Not Found\n");
    } else if (option == 3) {
        cout << "Length: " << length(head) << endl;
    } else if (option == 4) {
        int val;
        cout << "Enter value to insert at beginning: ";
        cin >> val;
        Node* newnode = new Node(val);
        insertAtBeginning(head, newnode);
        traversal(head);
    } else if (option == 5) {
        int val;
        cout << "Enter value to insert at end: ";
        cin >> val;
        Node* newnode = new Node(val);
        insertAtEnd(head, newnode);
        traversal(head);
    } else if (option == 6) {
        int val, pos;
        cout << "Enter value and position: ";
        cin >> val >> pos;
        Node* newnode = new Node(val);
        insertAtPosition(head, newnode, pos);
        traversal(head);
    } else if(option==7){
        deleteheadofsll(head);
        traversal(head);
    }
    else if(option==8){
        int pos;
        cout<<"enter position:";
        cin>>pos;
        deletespecificposofsll(head,pos);
        traversal(head);
    }
    else if(option==9){
        deleteatendofsll(head);
        traversal(head);
    }

    return 0;
}
