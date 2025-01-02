#include<iostream>
#include<string>
using namespace std;

int main(){
    string str;
    cin>>str;
    int i=0;
    while(str[i]!='\0'){
        if (str[i]==str[i+1]){
            str.erase(i,2);
            i=0;
        }
        else{i++;}


    }
    cout<<str;
}