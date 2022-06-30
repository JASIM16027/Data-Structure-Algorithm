#include <bits/stdc++.h>
using namespace std;

int getPathSum(int n, int m, vector<vector<int>> &matrix)
{
    vector<int>cur(n,0),prev(n,0);
    for (int j = 0; j <= m; j++)
        prev[j] = matrix[0][j];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            int leftdiagonal = -1e9, rightdiagonal = -1e9;
            int up = matrix[i][j] + prev[j];
            if (j - 1 >= 0)
                leftdiagonal = matrix[i][j] + prev[j - 1];
            if (j + 1 <= m)
                rightdiagonal = matrix[i][j] + prev[j + 1];
            cur[j] = max(up, max(leftdiagonal, rightdiagonal));
        }
        prev = cur;
    }
    int maxi = -1e9;
    for (int j = 0; j <= m; j++)
    {
        //cout<<dp[n][j]<<" ";
        maxi = max(maxi, prev[j]);
    }
    return maxi;
}

int main()
{
    vector<vector<int>> matrix{{1, 2, 10, 4}, {100, 3, 2, 1}, {1, 1, 20, 2}, {1, 2, 2, 1}};
    int n = matrix.size();
    int m = matrix[0].size();
    
    cout << getPathSum(n - 1, m - 1, matrix) << endl;
    return 0;
}