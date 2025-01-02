#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int d){
        this->data=d;
        this->next=NULL;
    }

} ;

void insert(int d,node*&head){
    if (head==NULL){
       head=new node(d);

    }
    else{
        node*s=head;                     //search pntr
        while(s->next!=NULL){
        s=s->next;
        }
        node*t=new node(d);
        s->next=t;

    }
}

void print(node*head){
    while(head!=NULL){
        cout<<head->data<<endl;
        head=head->next;
    }
}

void headinsert(int d,node* &head){
if(head==NULL){
    node* head=new node(d);
}
else{
    node*t=new node(d);
    t->next=head;
    head=t;
}

}

void insertatp(int p,int d,node*&head){
    if(p==1){
    headinsert(d,head);
    }
    else{
        node*s=head;
        for(int i=1;i<p-1;i++){
            s=s->next;
        }
        node*t=new node(d);
        t->next=s->next;
        s->next=t;

    }
}

void deletenode(int p,node*&head){

    if (p==1){
        head=head->next;
    }
    else{
    node*s=head;
    for(int i=1;i<p-1;i++){
        s=s->next;
    }
    s->next=s->next->next;
    }


}

void reverse(node*&head){
    node*p=NULL;
    node*c=head;
    node*n=head;
    if (head==NULL){
        return;
    }
    else{
        while(n!=NULL){
            n=n->next;
            c->next=p;
            p=c;
            c=n;
        }
    head=p;

    }


}

int main(){

node* head=NULL;
insert(10,head);

insert(15,head);

headinsert(0,head);

headinsert(-5,head);

insertatp(3,5,head);

insertatp(1,-10,head);

insert(20,head);

print(head);

cout<<"----------"<<endl;
reverse(head);

print(head);

cout<<"----------"<<endl;
reverse(head);

print(head);

return 0;
}