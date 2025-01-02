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
 void insertAtTail(node *&head,int d){
    node*temp=new node(d);
    if (head==NULL){
        head=temp;
    }
    else{
    node*tail=head;
    while (tail->next != NULL)
        {
            tail = tail->next;
        }
    temp->pre=tail;
    tail->next=temp;
    temp->next=NULL;

    }

  }
  void swap(node* &n) {
    cout << "swap\n";
    if (n == NULL || n->next == NULL) {
        return;
    }

    int k = n->data;
    n->data = n->next->data;
    n->next->data = k;
}
void merge(node*&head1,node*&head2){
    if (head1==NULL){
        head1=head2;
        head2=NULL;
    }
    else if(head2==NULL){}

    else{
         node*tail1=head1;
    while(tail1->next!=NULL){
        tail1=tail1->next;

    }
tail1->next=head2;
    head2=NULL;
    }


}

 void print(node* &s){
        node* temp=s;
        while (temp!=NULL)
        {cout<<temp->data<<" ";
          temp=temp->next;
          }
          cout<<endl;
 }
 int main(){
    int n,x;
    cin>>n;
    node*head=NULL;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        insertAtTail(head,t);
    }
    cin >>x;
node *n1=NULL;
node*n2=NULL;
node*temp=head;
while(temp!=NULL){
    if (temp->data<x){
    insertAtTail(n1,temp->data);
}
else{
    insertAtTail(n2,temp->data);
}
temp=temp->next;

}
merge(n1,n2);
print(n1);

    return 0;

 }
