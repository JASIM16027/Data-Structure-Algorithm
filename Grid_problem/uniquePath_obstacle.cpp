#include<bits/stdc++.h>
using namespace std;

int uniquePath(int i, int j, vector<vector<int>>&dp,vector<vector<int>>&maze){
   
    if (i>0 && j>0 && maze[i][j]==-1) return 0;
    if(i==0&&j==0){
        return 1;
    }
    if (i<0 || j<0){
        return 0;
    }
    
    if (dp[i][j]!=-1) return dp[i][j];

    int up = uniquePath(i-1,j,dp,maze);
    int left = uniquePath(i,j-1,dp, maze);
    return dp[i][j] = up+left;

}
int main(){
    int n,m;
    vector<vector<int> > maze{{0,0,0},
                            {0,-1,0},
                            {0,-1,0}};
    n = maze.size();
    m = maze[0].size();
    vector<vector<int> >dp(n,vector<int>(m,-1));
    cout<<uniquePath(n-1,m-1,dp,maze)<<endl;
    return 0;
}