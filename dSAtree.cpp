#include<iostream>
#include <queue>
using namespace std;

class leaf{
    public:
    int data;
    leaf* left;
    leaf* right;

    leaf(int k){
        this->data=k;
        this->left=NULL;
        this->right=NULL;
    }
};

void preorder(leaf*root){
    if(root==NULL){
        return;
    }

    cout<<root->data<<",";
    preorder(root->left);
    preorder(root->right);

}

void inodr(leaf* root){
    if(root==NULL){
        return;
    }
    inodr(root->left);
    cout<<root->data<<",";
    inodr(root->right);
}

void postorder(leaf*root){
    if (root==NULL){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data<<",";

}
int search(int arr[],int k,int s, int e){
    int i=s;
    for (i;i<=e;i++){
    if (arr[i]==k){
        return i;

    }
    }
        return -1;

}


leaf* buildtree(int preorder[],int inorder[],int s,int e){
if (s>e){
    return NULL;
}
    static int i=0;
    int curr=preorder[i];
    i++;
    leaf*root=new leaf(curr);
    int p=search(inorder,curr,s,e);
    root->left=buildtree(preorder,inorder,s,p-1);
    root->right=buildtree(preorder,inorder,p+1,e);
    return root;
}

leaf* buildtree2(int postorder[],int inorder[],int s,int e){
  if (s>e){
    return NULL;
  }

    static int i =6;
    int curr=postorder[i];
    i--;
    leaf* root=new leaf(curr);
    int p=search (inorder,curr,s,e);
    root->right=buildtree2(postorder,inorder,p+1,e);
    root->left=buildtree2(postorder,inorder,s,p-1);
    return root;

}

void levelorder(leaf*root){
    queue <leaf*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        leaf* k=q.front();
        q.pop();
        if (k!=NULL){
            cout<<k->data;
             if(k->left!=NULL){
                q.push(k->left);
            }
            if(k->right!=NULL){
                q.push(k->right);
            }

        }
        else{
            if (!q.empty()){
              q.push(NULL);
              cout<<endl;
            }
        }

    }


}

int sumatk (leaf*root,int k ){
    if (root==NULL){
    return -1;
}
queue <leaf*> q;
q.push(root);
q.push(NULL);
int lev=0;
int sum=0;

while(!q.empty()){
    leaf* t=q.front();
    q.pop();
    if (t==NULL){
        if(!q.empty()){
            lev++;
            q.push(NULL);
        }

    }
    else{
        if (lev==k){
           sum+= t->data;
        }
        if (t->left){
            q.push(t->left);
        }
        if (t->right){
            q.push(t->right);
        }
    }

}
return sum;

}

int countnode(leaf* root){

    if (root==NULL){
        return 0;
    }
    return countnode(root->left)+countnode(root->right)+1;

}

int sumofnodes(leaf*root){

if(root==NULL){
    return 0;
}
return sumofnodes(root->left)+sumofnodes(root->right)+root->data;
}

int heightoftree(leaf* root){
    if (root==NULL){
        return 0;
    }

    return max(heightoftree(root->left),heightoftree(root->right))+1;

    }



int diaoftree(leaf* root){
    if (root==NULL){
        return 0;
    }

    return max(heightoftree(root->left)+heightoftree(root->right)+1,max(diaoftree(root->left),diaoftree(root->right)));
    }

bool isbalanced(leaf*root){
    if (root==NULL){
        return true;
    }
    if (isbalanced(root->left)&&isbalanced(root->right)==false){
        return false;
    }
    if (abs(heightoftree(root->left)-heightoftree(root->right))<=1){
        return true;
    }
}

void leftview(leaf*root){

    queue<leaf*> q;
    q.push(root);
    while(!q.empty()){
        int t=q.size();
 for (int i=0;i<t;i++){
        leaf* l=q.front();
        q.pop();
        if (i==0){
            cout<<l->data<<" ";
        }
        if (l->left!=NULL){
            q.push(l->left);
        }
        if (l->right!=NULL){
            q.push(l->right);
        }

    }
    }

}

void rightview(leaf*root){

    queue<leaf*> q;
    q.push(root);
    while(!q.empty()){
        int t=q.size();
 for (int i=0;i<t;i++){
        leaf* l=q.front();
        q.pop();
        if (i==t-1){
            cout<<l->data<<" ";
        }
        if (l->left!=NULL){
            q.push(l->left);
        }
        if (l->right!=NULL){
            q.push(l->right);
        }

    }
    }

}

//        1
//     2     3
//   4  5 | 6  7
//       9      8
//        10
//         11
//          12
int main(){

    leaf* root=new leaf(1);
    root->left=new leaf(2);
    root->right=new leaf(3);
    root->left->left=new leaf(4);
    root->left->right=new leaf(5);
    root->left->right->right=new leaf(9);
    root->left->right->right->right=new leaf(10);
    root->left->right->right->right->right=new leaf(11);
    root->left->right->right->right->right->right=new leaf(12);
    root->right->left=new leaf(6);
    root->right->right=new leaf(7);
     root->right->right->right=new leaf(8);
    // preorder(root);
    // cout<<endl<<"-------------"<<endl;
    // inodr(root);
    // cout<<endl<<"-------------"<<endl;
    // postorder(root);

    // int preorder[]={1,2,4,5,3,6,7};
    // int inorder[]={4,2,5,1,6,3,7};
    // int pstorder[]={4,5,2,6,7,3,1};

   leftview(root);
   cout<<endl<<"-------------"<<endl;
   rightview(root);
    return 0;
}