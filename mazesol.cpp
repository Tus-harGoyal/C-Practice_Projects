#include <iostream>
#include <string>
using namespace std;
bool issafe(int **arr, int x, int y, int n)
{
    if ( x < n && y < n && arr[x][y] == 1 )
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool mazesolve(int **arr, int x, int y, int n, int **sol)
{

    if (issafe(arr, x, y, n))
    {
        if (x == n - 1 && y == n - 1)
        {
            sol[x][y] = 1;
            return true;
        }
        sol[x][y] = 1;
        if (mazesolve(arr, x + 1, y, n, sol))
        {
            return true;
        }
        if (mazesolve(arr, x, y + 1, n, sol))
        {
            return true;
        }
        if (mazesolve(arr, x-1, y, n, sol))
        {
            return true;
        }
        else
        {
            sol[x][y] = 0;
            return false;
        }
    }
    return false;
}

int main()
{cout <<"enter size of maze n X n = ";
    int n;
    cin >> n;
cout <<"input maze"<<endl;
    int **maze = new int *[n];
    for (int j = 0; j < n; j++)
    {
        maze[j] = new int[n];
    }
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> maze[j][i];
        }
    }
    int **mazesol = new int *[n];
    for (int j = 0; j < n; j++)
    {
        mazesol[j] = new int[n];
    }
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            mazesol[j][i] =0;
        }
    }

cout <<endl<<"solution"<<endl;
    if (mazesolve(maze, 0, 0, n, mazesol))
    {
         for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            cout << mazesol[j][i] <<" ";
        }
        cout<<endl;
    }
    }

    return 0;
}