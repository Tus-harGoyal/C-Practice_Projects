#include <iostream>
#include <stack>
#include<string>
using namespace std;


void solve(stack<int> &s,int n,int count){

 if (count ==n/2){
    s.pop();
    return;
 }
int num=s.top();
s.pop();


solve(s,n,count+1);
s.push(num);

}


int main(){
    stack<int> st;
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        int k;
        cin>>k;
        st.push(k);
    }
    solve(st,n,0);
     while(!st.empty()){
    cout<<st.top()<<" ";
    st.pop();
    }

}