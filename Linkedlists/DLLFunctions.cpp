#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};
void  traversal(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void backwardtraversal(Node*tail){
    Node*curr=tail;
     while(curr!=nullptr){
         cout<<curr->data<<" ";
         curr=curr->prev;
     }
}
int lengthofdll(Node*head){
    Node* curr=head;
    int cnt=0;
    while(curr!=nullptr){
        cnt++;
        curr=curr->next;
    }
    return cnt;
}
void insertionatbegingingofDLL(Node*&head,Node*newvalinsert){
    newvalinsert->next=head;
    if(head!=nullptr){
        head->prev=newvalinsert;
    }
    head=newvalinsert;
}
void insertionatendofDLL(Node*&head,Node*newnode1){
  
    if(head==nullptr){
       head=newnode1;
       return;
    }
      Node*temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
   temp->next=newnode1;
   newnode1->prev=temp;
}
int main(){
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;
   Node *head=nullptr;
   Node*tail=nullptr;
   for(int i=0;i<n;i++){
       int val;
       cin>>val;
       Node*newnode=new Node(val);
       if(head==nullptr){
           head=tail=newnode;
       }
       else{
           tail->next=newnode;
           newnode->prev=tail;
           tail=newnode;
       }
   }
   while(true){
  int option;
cout << "\nMenu:\n";
cout << "1. Forward Traversal\n";
cout << "2. Backward Traversal\n";
cout << "3. Length of Doubly Linked List\n";
cout << "4. Insert at Beginning\n";
cout << "5. Insert at END \n";
cout << "6. Exit PROGRAM \n";
cout<<"enter option:";
cin >> option;

   if(option==1){
      traversal(head); 
   }
   else if(option==2){
        backwardtraversal(tail);
   }
   else if(option==3){
      cout<<lengthofdll(head);
   }
   else if(option==4){
       int newval;
       cout<<"enter value to insert at Beginning:";
       cin>>newval;
       Node*newvalinsert=new Node(newval);
       insertionatbegingingofDLL(head,newvalinsert);
       traversal(head);
   }
   else if(option==5){
     int newval;
     cout<<"enter value to insert at end:";
       cin>>newval;
       Node*newnode1=new Node(newval);
       insertionatendofDLL(head,newnode1);
       traversal(head);
   }
   else {
       cout<<"exiting program....";
       break;
   }
    
   
   }
}