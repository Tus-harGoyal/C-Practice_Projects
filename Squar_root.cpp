#include <iostream>
#include <cmath>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;
int main(){

long double num=3;
double low=0;
long double high=num;
long double midold=0;
double tol=1e-92;
while (low<=high){
    long double mid=(high+low)/2;
    if (fabs(midold-mid)<tol){
        break;
    }
    if (mid*mid>num){
        high=mid;
    }
    else{
        low=mid;
    }
    midold=mid;

    cout<<"guess= "<<setprecision(30)<<mid<<endl;

}


 return 0;

}