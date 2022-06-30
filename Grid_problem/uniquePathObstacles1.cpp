#include<bits/stdc++.h>
using namespace std;

int mazeObstacles(int n, int m, vector<vector<int>>&dp, vector<vector<int>>&maze){
    for(int i=0; i<=n;i++){
        for(int j=0;j<=m;j++){

            if ( i>0 && j>0 && maze[i][j]==-1) {
                dp[i][j] = 0;
                continue;
                
                }
            if (i==0 && j==0){
                dp[i][j] = 1;
                continue;
            }

            
            int up = 0, left=0;
            if (i>0) up = dp[i-1][j];
            if (j>0) left = dp[i][j-1];

            dp[i][j] = up+left;
        }
    }
    return dp[n][m];
}

int main(){

    vector<vector<int> > maze{{0,0,0},{0,-1,0},{0,-1,0}};
    int n = maze.size();
    int m = maze[0].size();
    vector<vector<int>>dp(n, vector<int>(m,-1));
    cout<<mazeObstacles(n-1,m-1,dp,maze)<<endl;                       
                            
    return 0;
}