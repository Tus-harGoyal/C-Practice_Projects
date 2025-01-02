#include <iostream>

using namespace std;

int main()
{
    char button;
    cout<<"enter a character:-";
    cin>>button;
    switch (button)
    {
        case 'a':
            cout<<"hello";
            break;

        case 'b':
            cout<<"namaste";
            break;
        case 'c':
            cout<<"Hola";
            break;
        default:
        cout<<"still learning";

    }
    return 0;
}