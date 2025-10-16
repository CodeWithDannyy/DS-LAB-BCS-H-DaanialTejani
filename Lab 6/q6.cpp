#include<iostream>
using namespace std;

bool safe(int n, int r, int c, int a[10][10], bool vis[10][10])
{
    if(r < 0 || c < 0 || r >= n || c >= n)
    {
        return false;
    }
    if(a[r][c] == 0)
    {
        return false;
    }
    if(vis[r][c])
    {
        return false;
    }
    return true;
}

bool dfs(int n, int r, int c, int a[10][10], bool vis[10][10], int path[10][10])
{
    if(r == n - 1 && c == n - 1)
    {
        path[r][c] = 1;
        return true;
    }
    vis[r][c] = true;
    path[r][c] = 1;

    if(safe(n, r - 1, c, a, vis) && dfs(n, r - 1, c, a, vis, path))
    {
        return true;
    }
    if(safe(n, r + 1, c, a, vis) && dfs(n, r + 1, c, a, vis, path))
    {
        return true;
    }
    if(safe(n, r, c - 1, a, vis) && dfs(n, r, c - 1, a, vis, path))
    {
        return true;
    }
    if(safe(n, r, c + 1, a, vis) && dfs(n, r, c + 1, a, vis, path))
    {
        return true;
    }

    path[r][c] = 0;
    vis[r][c] = false;
    return false;
}

int main()
{
    int n = 5;
    int a[10][10] =
    {
        {1,1,0,1,1},
        {0,1,1,1,0},
        {0,1,0,1,1},
        {1,1,1,0,1},
        {0,0,1,1,1}
    };

    bool vis[10][10] = {false};
    int path[10][10] = {0};

    if(dfs(n, 0, 0, a, vis, path))
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cout << path[i][j] << (j + 1 == n ? '\n' : ' ');
            }
        }
    }
    else
    {
        cout << "No path\n";
    }
}
