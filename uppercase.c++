#include<iostream>
using namespace std;
int main(){
    string str;
    getline(cin,str);


    for (int i=0;i<str.length();i++){    //last character is removed automatically
        if(str[i]>='a'&&str[i]<='z'){
            str[i]=str[i]-32;            //because UC and LC differ by 32;
        }
    }
    cout<<"UC "<<str<<endl;
      for (int i=0;i<str.length();i++){    //last character is removed automatically
        if (str[i]!=' '||str[i]!='\0'){
            str[i]=str[i]+32;            //because UC and LC differ by 32;
        }
        }

    cout<<"LC "<<str<<endl;
    return 0;
}