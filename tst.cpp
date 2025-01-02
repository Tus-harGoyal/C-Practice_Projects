#include <iostream>
#include <string>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int d)
    {
        data = d;
        next = NULL;
    }
};

void insertathead(node *&head, int k)
{
    if (head == NULL)
    {
        node *n = new node(k);
        head = n;
    }
    else
    {
        node *n = new node(k);
        n->next = head;
        head = n;
    }
}

void insertattail(node *&head, int k)
{
    node *tail = head;

    if (tail == NULL)
    {
        node *n = new node(k);
        tail = n;
        head = n;
    }

    else
    {
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        node *n = new node(k);
        tail->next = n;
        tail = n;
    }
}

node *reverse(node *&head)
{
    if (head->next == NULL)
    {
        return head;
    }
    else
    {
        node *pre = NULL;
        node *curr = head;
        node *frd = head;
        while (frd != NULL)
        {
            frd = curr->next;
            curr->next = pre;
            pre = curr;
            curr = frd;
        }
        head = pre;
        return pre;
    }
}

void print(node *&head)
{

    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


int main()
{
    int n,k;
    cin >> n ;
    node *n1 = NULL;
    node *head = n1;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        insertattail(head, k);
    }
    cin >>k;
    if (k==0||n==1){
        print(head);
        return 0;
    }
    node* temp=head;
    node*curr=head;
    node *tail = head;\
    while (tail->next != NULL)
        {
            tail = tail->next;
        }


    for(int j=0;j<k;j++){
        curr=curr->next;
        tail->next=temp;
        temp->next=NULL;
        tail=temp;
        temp=curr;
    }
    print(curr);

    }
