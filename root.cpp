#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

#define f(x) x*x - 4

long double mid(long double x, long double y)
{
    return (x + y) / 2;
}

int main()
{
    cout << setprecision(6) << fixed;
    long double x0, x1, x2, f0, f1, f, tol;
    cin >> x0 >> x1 >> tol;
    x2=x1;
    f0 = f(x0);
    f1 = f(x1);

    do
    {

        if (f0 * f1 < 0)
        {
            x2 = mid(x0, x1);
            f = f(x2);
            if (f0 * f == 0)
            {
                cout<<"break"<<endl;
                break;
            }
            if (f0 * f < 0)
            {
                x1 = x2;
            }

            if (f0 * f > 0)
            {
                x0 = x2;
            }


            cout <<x2<<"      "<<f<<endl;
        }
    }while (abs(f) > tol);

    cout <<"root= "<< x2;
}