#include<iostream>
using namespace std;

class students{
    string name;
    public:
    int age ;
    int gender;


    students(){
        cout <<"default construcctor was called. "<<endl;
    }
    students(string str,int a,int b){
        name=str;
        age=a;
        gender=b;
        cout <<"data constructor was called."<<endl;
    }
    students(students &a){
        name=a.name;
        age=a.age;
        gender=a.gender;
        cout<<"copy constructor was called."<<endl;
    }
    bool operator = (students &a){
        if (name==a.name&&age==a.age&&gender==a.gender){
            return true;
        }
        return false;
    }



};


int main(){
students a("tushar",19,0);
students b;
students c(a);
if (a=c){cout <<"a and c are same "<<endl;}
else cout <<"different"<<endl;

    return 0;
}