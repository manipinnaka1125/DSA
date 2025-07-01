#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data1){
        this->data=data1;
        this->next=nullptr;
    }
};
void traversal(Node * head){
    if(head==nullptr){
        cout<<endl;
        return;
    }
    cout<<head->data;
    cout<<endl;
    head=head->next;
    traversal(head);
    
}


int main(){
int n;
cin>>n;
Node*head=nullptr;
Node*tail=nullptr;
for(int i=0;i<n;i++){
    int val;
    cin>>val;
    Node*newnode=new Node(val);
    if(head==nullptr){
        head=tail=newnode;
    }else{
        tail->next=newnode;
        tail=newnode;
    }
}
traversal(head);
 
}