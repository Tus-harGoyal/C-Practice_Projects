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


void print(node* &s){
        node* temp=s;
        while (temp!=NULL)
        {cout<<temp->data<<" ";
          temp=temp->next;
          }
          cout<<endl;
}

void insert(node* &tail,node*&head,int k){
    if (head==NULL){
        node*nod=new node(k);
        tail=nod;
        head=nod;
    }
    else{
    node*nod=new node(k);
    tail->next=nod;
    tail=nod;
    }

    }

node* reverse(node* &head){
    node*prev=NULL;
    node*current=head;
    node*forward=NULL;
    while(current!=NULL){
    forward=current->next;
    current->next=prev;
    prev=current;
    current=forward;

    }
    return prev;
}
node*reversecpy(node*&head){
    node*head1=reverse(head);
    node*head2=NULL;
    node*tail2=head2;
    while(head1!=NULL){

        insert(tail2,head2,head1->data);
        head1=head1->next;
    }
    tail2->next=NULL;
    reverse(head1);
    return head2;



}
int middle(node*head){
    cout<<"entered middle"<<endl;
    int mid=0;
    while(head!=NULL){
        head=head->next;
        mid++;
    }
    mid=mid/2;
    return mid;
}

node* fold(node*head,int n){
    cout <<"entered fold"<<endl;
    node*pre=head;
    node*c1=pre;
    print(c1);
    node*c2=reverse(head);
    print(c1);
    print(c2);
    node*temp1=c1->next;
    node*temp2=c2->next;
    int cnt=0;
    while(cnt<n/2){
        cout <<"enterred loop"<<endl;
        c1->next=c2;
        c2->next=temp1;
        c1=temp1;
        c2=temp2;
        temp1=temp1->next;
        temp2=temp2->next;
        cnt++;
    }
    cout <<"exited loop"<<endl;
    if(n%2!=0){
        c1->next=NULL;

    }
    else{
        c1=NULL;
    }
cout <<"returning"<<endl;
    return pre;
}

int main(){
    int n;
    cin >> n;

    // create the linked list
    node* n1 = NULL;
    node* head = n1;
    node* tail = n1;
    for (int i = 0; i < n; i++){
        int k;
        cin >> k;
        insert(tail, head, k);
    }

    // check if the linked list is empty
    if (head == NULL) {
        cout << "The linked list is empty." << endl;
        return 0;
    }

    // check if the size of the linked list is at least 2
    if (n < 2) {
        cout << "The linked list should have at least 2 elements." << endl;
        return 0;
    }

node*head2=reversecpy(head);
print(head);
print (head2);
    return 0;
}


