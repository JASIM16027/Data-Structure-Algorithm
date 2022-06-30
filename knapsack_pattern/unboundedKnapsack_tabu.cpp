#include <bits/stdc++.h>
using namespace std;
int unboundedKnapsack(int n, int wt[], int val[], int W, vector<vector<int>> &dp)
{
    for (int w = 0; w <= W; w++)
        dp[0][w] = (w / wt[0]) * val[0];
    for (int ind = 1; ind <=n; ind++)
    {
        for (int w = 0; w <= W; w++)
        {
            int nottake = 0 + dp[ind - 1][w];
            int take = INT_MIN;
            if (wt[ind] <= w)
            {
                take = val[ind] + dp[ind][w- wt[ind]];
            }

            dp[ind][w] = max(nottake, take);
        }
    }
    return dp[n][W];

    
}
int main()
{

    int wt[] = {2, 4, 6};
    int val[] = {10, 19, 16};
    int w = 10;
    int n = sizeof(wt) / sizeof(wt[0]);
    vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    cout << unboundedKnapsack(n - 1, wt, val, w, dp) << endl;
    return 0;
}