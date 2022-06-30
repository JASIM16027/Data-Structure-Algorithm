#include<bits/stdc++.h>
using namespace std;
int minimumPathSum(int i, int j, vector<vector<int>>&dp, vector<vector<int>>&board){
    if (i==0 && j==0) return board[0][0];
    if (i<0||j<0) return 1e9;
    if (dp[i][j]!=-1) return dp[i][j];
    
    int up = board[i][j]+minimumPathSum(i-1,j,dp,board);
    int left = board[i][j]+minimumPathSum(i,j-1,dp,board);

    return dp[i][j]  = min(up,left);
}
int main(){
    vector<vector<int>>board{{10,8,2},{10,5,100},{1,1,2}};
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>>dp(n, vector<int>(m,-1));
    cout<<minimumPathSum(n-1,m-1,dp,board)<<endl;
    return 0;
}