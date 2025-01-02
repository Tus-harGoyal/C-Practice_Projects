#include <iostream>
#include <cmath>
using namespace std;

long double guess(long double x){
    return 0.5*(x+2/x);
}

int main(){

    long double tv=sqrt(2);
    long double prec=0.001;

    long double i=0.1;
    int itr=0;
    while (true){
        cout<<i<<endl;
        if (abs(tv-i)<prec){
            break;
        }
        i=guess(i);
        itr++;

    }

cout <<"itr=="<<itr<<" "<<"target= "<<tv;
    return 0;

}