#include<iostream>
using namespace std;

class node{
    public :
    int data;
    node* pre;
    node* next;

    node (int a){
        data=a;
        pre=NULL;
        next=NULL;
    }

};
  void insertAtTail(node *&tail,int d){
    node*temp=new node(d);
    temp->pre=tail;
    tail->next=temp;
    tail=temp;
  }
 void print(node* &s){
        node* temp=s;
        while (temp!=NULL)
        {cout<<temp->data<<" ";
          temp=temp->next;
          }
          cout<<endl;
 }
 void insertAtHead(node* &head,int k){
    node* temp=new node(k);
    temp->next=head;
    head->pre=temp;
    head=temp;
 }

void insertAtx(node* &head,int pos,int k){
    node*n=new node(k);
    node* temp=head;
    for (int j=1;j<pos-1;j++){
       temp=temp->next;
    }
    n->next=temp->next;
    temp->next->pre=n;
    n->pre=temp;
    temp->next=n;

}
void deletenode(int x,node* &head){
node* prev=NULL;
node* curr=head;
for (int i=1;i<x;i++){
    prev=curr;
    curr=curr->next;
}
curr->next->pre=prev;
prev->next=curr->next;
curr->pre=NULL;
curr->next=NULL;
delete curr;
}

int main(){
    node* p=new node(10);
    node *head=p;
    node *tail=p;
    insertAtTail(tail,9);
    insertAtTail(tail,5);
    insertAtTail(tail,4);
    insertAtHead(head,12);
    insertAtHead(head,15);
    insertAtx(head,5,11);
    print(head);
    print(head);

    // int x;
    // cin>>x;
    // deletenode(x,head);
    // print(head);
    return 0;
}