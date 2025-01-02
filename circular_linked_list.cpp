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
        node* temp = new node(k);
        node* t = tail;
        while (t->data != target){
            t = t->next;
        }
        temp->next = t->next;
        t->next = temp;


}


void print(node *&tail){
    node* temp = tail;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while(temp != tail);
    cout << endl;
}



int main(){
    node *n=new node(10);
    node *tail=n;
    insert(tail,10,5);

    print(tail);
    print(tail);

}
