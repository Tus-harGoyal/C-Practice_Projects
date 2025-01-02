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

};
    void insertAtTail(node* &tail,int k){            //here we used referrence so that the tail gets permanently changed
        node*n=new node(k);
        tail->next=n;
        tail=n;

    }
    void insertAtHead(node* &head,int k){
        node* temp=new node(k);
        temp->next=head;
        head=temp;
    }
    void insertAtx(int x,int k,node *&head,node* &tail){
          node* t=head;
        int count=0;
        while(t!=NULL){
            t=t->next;
            count++;
        }
            // //case2 x=head
        if(x==1){
            insertAtHead(head,k);
        }

            // //case3 if x>tail

        else if (x>count){
            insertAtTail(tail,k);
        }
        else{
        //case1 head<x<tail
        node*temp=new node(k);
        node*p=head;
        for (int i=1;i<x-1;i++){p=p->next;}
        temp->next=p->next;
        p->next=temp;

        }





    }
    void print(node* &s){
        node* temp=s;
        while (temp!=NULL)
        {cout<<temp->data<<" ";
          temp=temp->next;
          }
    }
    void del(int x,node* &head,node* &tail){
        if (x!=1){
            node* prev=NULL;
            node*temp=head;
            for (int i=1;i<x;i++){
                prev=temp;
                temp=temp->next;
            }
            if (temp->next==NULL){
                tail=prev;
                prev->next=NULL;
                delete temp;

            }
            else {

            prev->next=temp->next;
            temp->next=NULL;
            delete temp;
            }
        }
        else{
        if (x==1){
            node*temp=head;
            head=head->next;
            temp->next=NULL;
            delete temp;
        }
        }


    }

int main(){

node*n1 =new node(10);
node* head=n1;
node* tail=n1;
// cout <<p->data<<endl;
// cout <<p->next;
insertAtTail(tail,20);
insertAtTail(tail,300);
insertAtHead(head,12);
insertAtHead(head,24);

cout<<endl;
insertAtx(3,69,head,tail);

insertAtx(100,6,head,tail);
print (head);
cout<<endl;
int n;
cin>>n;
del(n,head,tail);
print(head);
cout <<endl<<head->data<<endl<<tail->data<<endl;
// insertAtx(0,6,head,tail);insertAtx(5,78,head,tail);insertAtTail(tail,77);
// insertAtx(15,500,head,tail);
// print (head);
    return 0;
}