#include <iostream>
#include <stack>
#include<string>
using namespace std;

int main(){

stack <char > str;
string s;
getline(cin,s);

for (int i=0;i<s.length();i++){
str.push(s[i]);
cout<<"pushed "<<s[i]<<"   ";
}
cout <<endl;
string ans="";
while(!str.empty()){
    ans.push_back(str.top());           ///pushback is used to append the string . it allots new memory as we define the new characters
    str.pop();


}
cout<< ans;

    return 0;
}