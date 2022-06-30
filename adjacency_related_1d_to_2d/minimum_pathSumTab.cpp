#include <bits/stdc++.h>
using namespace std;

int minimumPathSum(int n, int m, vector<vector<int>> &dp, vector<vector<int>> &board)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = board[i][j];
                continue;
            }
            int up = INT_MAX, left = INT_MAX;
            if (i > 0)
            {
                up = board[i][j] + dp[i - 1][j];
            }
            if (j > 0)
            {
                left = board[i][j] + dp[i][j - 1];
            }

            dp[i][j] = min(up, left);
        }
    }
    return dp[n][m];
}
int main()
{
    vector<vector<int>> board{{5,9,6},{11,5,2}};//{{10, 8, 2}, {10, 5, 100}, {1, 1, 2}};
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << minimumPathSum(n - 1, m - 1, dp, board) << endl;
    return 0;
}