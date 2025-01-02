#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{

    stack<char> str;
    string s;
    getline(cin, s);

    for (int i = 0; i < s.length(); i++)
    {

        str.push(s[i]);
    }
    string ans;

    int i = 0;
    while (!str.empty())
    {
        ans[i] = str.top();
        str.pop();
        i++;
    }
    ans[i] = '\0';
    cout << ans;

    return 0;
}