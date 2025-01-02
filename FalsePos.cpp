#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

#define f(x) x*x-9

int main(){
double x0,x1,x2,f0,f1,f2,tol;
tol=0.0001;
cout<<setprecision(6)<<fixed;
cin>>x0>>x1;
f0=f(x0);
f1=f(x1);
do{
x2=x0-((x0-x1)*f0)/(f0-f1);
f2=f(x2);
if (f0*f2==0){
        x1=x2;
        cout<<"found root="<<x2<<endl;
        break;
    }
else if (f0*f1<0){
    // cout<<"root tapped"<<endl;


 if (f0*f2<0){
        x1=x2;
        cout<<"f0*f2<0"<<endl;
    }
else{
    cout<<"f0*f2>0"<<endl;
        x0=x2;
    }
    cout<<"new x2= "<<x2<<"     f2="<<abs(f2)<<endl;


}

}while(abs(f(x2))>0.01);
cout<< "exited while";


    return 0;
}