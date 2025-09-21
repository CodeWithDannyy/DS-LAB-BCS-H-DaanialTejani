#include<iostream>
using namespace std;

bool isValid(int a[9][9], int r, int c, int v)
{
    for(int i = 0; i < 9; i++)
    {
        if(a[r][i] == v || a[i][c] == v)
        {
            return false;
        }
    }
    int sr = (r/3)*3, sc = (c/3)*3;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(a[sr+i][sc+j] == v)
            {
                return false;
            }
        }
    }
    return true;
}

bool solve(int a[9][9])
{
    for(int r = 0; r < 9; r++)
    {
        for(int c = 0; c < 9; c++)
        {
            if(a[r][c] == 0)
            {
                for(int v = 1; v <= 9; v++)
                {
                    if(isValid(a, r, c, v))
                    {
                        a[r][c] = v;
                        if(solve(a))
                        {
                            return true;
                        }
                        a[r][c] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int a[9][9] =
    {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };

    cout << "Orginal Sudoku : " << endl;
    for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                cout << a[i][j] << (j == 8 ? '\n' : ' ');
            }
        }

    cout << endl;
    cout << "Solved Sudoku : " << endl;
    if(solve(a))
    {
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                cout << a[i][j] << (j == 8 ? '\n' : ' ');
            }
        }
    }
    else
    {
        cout << "No solution\n";
    }
}
