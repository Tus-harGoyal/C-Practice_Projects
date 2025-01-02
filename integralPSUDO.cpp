#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double f(double x){
    return x*x;
}

int main(){
cout << setprecision(6) << fixed;
double x1,x2,h,A;
x1=0;
x2=1;
double Tol=1e-5;

    for(int i=0;i<100;i++){

        A=0;
        int n,I;
        n=1;
        I=0;
        h=abs((x1-x2)/pow(2,i));
        while(true){
            A=A+(f(n*h+x1)*(h));
            if (n*h+x1>=x2){
                cout<<A<<"I= "<< I<<endl;
                break;
            }
            n++;
            I++;
        }


}
return 0;
    }
