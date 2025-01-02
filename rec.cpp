#include<iostream>
using namespace std;

int fibb(int n){
    if (n==1){
        return 1;
    }
    if (n==0){
        return 0;
    }
    return fibb(n-2)+fibb(n-1);
}


int powerof2(int n){

    if (n==1){
        return 2;
    }
    return 2*powerof2(n-1);
}

int main(){
    for (int i=1;i<=20;i++){
        cout <<powerof2(i)<<" ";
    }

    return 0;
}