#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

#define f(x) x*x+9-6*x
#define g(x) 2*x-3;


int main(){
    cout<<setprecision(8)<<fixed;

    double x0,x1,e,g0,f0;
    int N=0;
    e=1e-6;
    cin>>x0;
    while(N<200){
       g0= g(x0);
       f0 =f(x0);
    if (g0==0){
        cout <<"not convergent ";
    }
    x1=x0-(f0/g0);
    if (abs(f(x1))>e){
        x0=x1;
    }
   else{
    N++;
    break;
   }

    N++;
    cout<< N<<"     "<<x1<<endl;
    }
cout<< N<<"     "<<x1<<endl;
    return 0;
}