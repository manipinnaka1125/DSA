#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
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
bool searchinginlinkedlist(Node*head,int search){
    Node*curr=head;
    while(curr!=nullptr){
        if(curr->data==search){
            return true;
        }
        curr=curr->next;
    }
    return false;
}

int main(){
int n;
cout<<"enter nodes:";
cin>>n;
cout<<endl;
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
int search;
cout<<"enter element to search:";
cin>>search;
if(searchinginlinkedlist(head,search)){
    cout<<"yes element found";
}
else
{
    cout<<"no";
}
 
}