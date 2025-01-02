#include<iostream>
using namespace std;


    class node{
    public:
    int data;
    node *next;
    int size;


    node(int d)
    {
        data = d;
        next = NULL;
    }
    void setsize(int n){
        size=n;
    }
    };

void push(int k,node*&head){
    if (head!=NULL){
    node* n=new node(k);
    n->next=head;
    head=n;
    }
    else{
      node* n=new node(k);
      head=n;
    }
}

void pop(node*&head){
    cout<<"entered pop  ";
    if (head->next==NULL) {
        head=NULL;
        cout<<"     entered if   ";
        cout << "   stack underflow     " ;
    cout<<"     exit if   ";
    }
    else{
        cout<<"     entered else    ";
        node*temp=head;
        head=head->next;
        temp->next=NULL;


    }
    // cout <<"new head="<<head->data;
    cout<<"exiting pop"<<endl;

}

int peek(node* &head){
    return head->data;
}

bool isEmpty(node* head){
    if (head==NULL){
        return true;
    }
    else{
        return false;
    }
}






int main(){

node *st = NULL;
node *head = st;
st->setsize(5);
push(10,head);
push(20,head);
push(30,head);
push(40,head);
cout <<peek(head)<<endl;




    return 0;
}