#include <iostream>

using namespace std;

int main(){

int m;
cout<<"num=";
cin>>m;
int i,flag;
for (i=2;i<m;i++)
{
    if (m%i==0){
        flag=1;
        break;
    }
    else{
        flag=0;
    }
}
switch(flag)
{
    case 1:cout<<"not prime";break;
    case 0:cout<<"prime";break;
}
    return 0;
}