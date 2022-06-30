#include <bits/stdc++.h>

using namespace std;

int mazeObstacles(int n, int m, vector<vector<int>> &maze)
{

    vector<int> prev(m, 0);
    for (int i = 0; i < n; i++)
    {
        vector<int> cur(m, 0);
        for (int j = 0; j < m; j++)
        {
            if (i > 0 && j > 0 && maze[i][j] == -1)
            {
                cur[j] = 0;
                continue;
            }
            if (i == 0 && j == 0)
            {
                cur[j] = 1;
                continue;
            }

            int up = 0;
            int left = 0;

            if (i > 0)
                up = prev[j];
            if (j > 0)
                left = cur[j - 1];

            cur[j] = up + left;
        }
        prev = cur;
    }

    return prev[n - 1];
}

int main()
{

    vector<vector<int>> maze{{0, 0, 0},
                             {0, -1, 0},
                             {0, 0, 0}};

    int n = maze.size();
    int m = maze[0].size();

    cout << mazeObstacles(n, m, maze);
    return 0;
}