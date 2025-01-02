#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    getline(cin,str);
    string temp="";

    int pnt=0;
    int nword=1;
    //word count

     for (int i=0;i<str.length();i++){
        if (str[i]==' '){
            nword++;
        }
     }
     cout <<"no of words="<<nword<<endl;
      string *word = new string[nword];
    int j=0;
    for (int i=0;i<str.length();i++){
        if (str[i]!=' '){
            temp=temp+str[i];

        }
        if (str[i]==' '||i == str.length() - 1){
            word[j]=temp;
            temp.clear();
            // cout <<word[j]<<endl;
            j++;
        }
    }

    for (int i=(nword-1);i>=0;i--){
        cout<<word[i]<< " ";
    }


return 0;
}




