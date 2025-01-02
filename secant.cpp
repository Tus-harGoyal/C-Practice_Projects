#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

#define f(x) x*x-9

int main(){
    int n=0;
double x0,x1,x2,f0,f1,f2,tol;
tol=0.0001;
cout<<setprecision(6)<<fixed;
cin>>x0>>x1;
f0=f(x0);
f1=f(x1);
do{
x2=x1-((x1-x0)*f1)/(f1-f0);
f2=f(x2);
n++;
cout<<"itr= "<<n<<"     x2= "<<x2<<"     f2="<<f2<<endl;
x0=x1;
f0=f1;
f1=f2;
x1=x2;

}while(abs(f2)>0.0001);
cout<< "exited while";


    return 0;
}