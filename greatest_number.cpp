#include<iostream>
#include<string>
using namespace std;
int main(){
string str;
cin>>str;
char temp;
int count=0;
while(count<str.length()-1){
for(int i=1;i<str.length();i++){
    if (str[i]>str[i-1]){
        temp=str[i];
        str[i]=str[i-1];
        str[i-1]=temp;
    }
}
count++;
}
cout<<str;
return 0;
}


