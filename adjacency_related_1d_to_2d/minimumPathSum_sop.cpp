#include <bits/stdc++.h>
using namespace std;

int minimumPathSum(int n, int m,vector<vector<int>> &board)
{
    vector<int>prev(n+1,0);
    for (int i = 0; i <= n; i++)
    {
        vector<int>cur(n+1,0);
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 && j == 0)
            {
                cur[j] = board[i][j];
                continue;
            }
            int up = INT_MAX, left = INT_MAX;
            if (i > 0)
            {
                up = board[i][j] + prev[j];
            }
            if (j > 0)
            {
                left = board[i][j] + cur[j - 1];
            }

            cur[j] = min(up, left);
            
        }
        prev = cur;
    }
    return prev[m];
}
int main()
{
    vector<vector<int>> board{{10, 8, 2}, {10, 5, 100}, {1, 1, 2}};
    int n = board.size();
    int m = board[0].size();
    //vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << minimumPathSum(n - 1, m - 1,board) << endl;
    return 0;
}