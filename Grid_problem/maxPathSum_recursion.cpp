#include <bits/stdc++.h>
using namespace std;

int getMaxPathSum(int i, int j, int m, vector<vector<int>> &dp,
                  vector<vector<int>> &matrix)
{
    if (j < 0 || j > m)
        return -1e9;
    if (i == 0)
        return matrix[0][j];
    if (dp[i][j] != -1)
        return dp[i][j];

    int up = matrix[i][j] + getMaxPathSum(i - 1, j, m, dp, matrix);
    int leftdiagonal = matrix[i][j] + getMaxPathSum(i - 1, j - 1, m, dp, matrix);
    int rightdiagonal = matrix[i][j] + getMaxPathSum(i - 1, j + 1, m, dp, matrix);
    
    return dp[i][j] = max(up, max(leftdiagonal, rightdiagonal));
}
int main()
{

    vector<vector<int>> matrix{{1, 2, 10, 4}, {100, 3, 2, 1}, {1, 1, 20, 2}, {1, 2, 2, 1}};
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int maxi = -1e9;
    for (int j = 0; j < m; j++)
    {
        int ans = getMaxPathSum(n - 1, j, m - 1, dp, matrix);
        maxi = max(maxi, ans);
    }
    cout << maxi << endl;
    return 0;
}