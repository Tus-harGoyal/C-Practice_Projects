#include<iostream>
using namespace std;

class node {
    public:
    int data;
    node* next;
    node (int val){
        data=val;
        next=NULL;
    }
    ~node(){
        delete next;
        next=NULL;
    }
};


void insert(node*& tail, int target, int k){
    if (tail==NULL){
        node*node1=new node(k);
        tail=node1;
        tail->next=tail;
    }
    else{
        node*current=tail;
        while(current->data!=target){
            current=current->next;
        }
        node*temp=new node(k);
        temp->next=current->next;
        current->next=temp;
    }

}

void print(node* tail){
    node*temp=tail;
    do{
        cout <<tail->data<<" ";
        tail=tail->next;
    }

    while(tail!=temp);
    cout <<endl;
}

void del(int k,node*&tail){
    node*prev=tail;
    node*current=tail->next;
    if (tail==NULL){
        cout<<"list is empty"<<endl;
    }
    else{
        while(current->data!=k){
            prev=current;
            current=current->next;
            if (current==tail && current->data!=k){
                cout<<"key not found"<<endl;
                return;
            }
        }
        if (current==tail){
            tail=tail->next;
        }
        prev->next=current->next;
        current->next=NULL;
    }
}

int main(){
    node* tail=NULL;
    insert(tail,4,10);
    insert(tail,10,50);
    insert(tail,50,60);
    insert(tail,60,80);
    print(tail);
    del(10,tail);
    print(tail);


}