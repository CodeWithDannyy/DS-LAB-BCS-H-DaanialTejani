#include<iostream>
using namespace std;

int iabs(int x)
{
    if(x < 0)
    {
        return -x;
    }
    return x;
}

bool canPlace(int row, int col, int* pos)
{
    for(int r = 0; r < row; r++)
    {
        if(pos[r] == col)
        {
            return false;
        }
        if(iabs(pos[r] - col) == iabs(r - row))
        {
            return false;
        }
    }
    return true;
}

void printBoard(int n, int* pos)
{
    for(int r = 0; r < n; r++)
    {
        for(int c = 0; c < n; c++)
        {
            if(pos[r] == c)
            {
                cout << 'Q';
            }
            else
            {
                cout << '.';
            }
        }
        cout << '\n';
    }
    cout << '\n';
}

void solveNQ(int n, int row, int* pos, long long& ways)
{
    if(row == n)
    {
        ways++;
        printBoard(n, pos);
        return;
    }
    for(int c = 0; c < n; c++)
    {
        if(canPlace(row, c, pos))
        {
            pos[row] = c;
            solveNQ(n, row + 1, pos, ways);
            pos[row] = -1;
        }
    }
}

int main()
{
    int n;
    cout << "Enter N: ";
    cin >> n;
    int* pos = new int[n];
    for(int i = 0; i < n; i++)
    {
        pos[i] = -1;
    }
    long long ways = 0;
    solveNQ(n, 0, pos, ways);
    cout << "Total solutions: " << ways << '\n';
    delete[] pos;
}
