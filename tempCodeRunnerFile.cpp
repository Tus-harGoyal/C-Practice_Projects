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
        leaf* t= q.front();
        q.pop();
        if(t!=NULL){
            if (t->left){
                q.push(t->left);
            }
            if (t->right){
                q.push(t->right);
            }
            if (lev==k){
                    sum+=t->data;

            }


        }
        else{
            if (!q.empty()){
                q.push(NULL);
                lev++;
            }
    }
    return sum;

    }

}

//        1
//     2     3
//   4  5 | 6  7
int main(){

    leaf* root=new leaf(1);
    root->left=new leaf(2);
    root->right=new leaf(3);
    root->left->left=new leaf(4);
    root->left->right=new leaf(5);
    root->right->left=new leaf(6);
    root->right->right=new leaf(7);
    // preorder(root);
    // cout<<endl<<"-------------"<<endl;
    // inodr(root);
    // cout<<endl<<"-------------"<<endl;
    // postorder(root);

    // int preorder[]={1,2,4,5,3,6,7};
    // int inorder[]={4,2,5,1,6,3,7};
    // int pstorder[]={4,5,2,6,7,3,1};

   sumatk(root,3);
    return 0;
}