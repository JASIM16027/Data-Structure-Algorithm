#include<bits/stdc++.h>
using namespace std;
int minimumSumTriangle(int i,int j,int n,vector<vector<int>>&dp, 
vector<vector<int>>&triangle){
    
    if (dp[i][j]!=-1) return dp[i][j];
    if (i==n-1) return triangle[i][j];
    int down = triangle[i][j]+minimumSumTriangle(i+1,j,n,dp,triangle);
    int diagonal = triangle[i][j]+minimumSumTriangle(i+1,j+1,n,dp,triangle);
    return dp[i][j]=min(down, diagonal);
}
int main(){
    vector<vector<int> > triangle{{1},{2,3},{3,6,7},{8,9,6,10}};
    int n = triangle.size();
    vector<vector<int>>dp(n, vector<int>(n,-1));
    cout<<minimumSumTriangle(0,0,n,dp,triangle)<<endl;
                                
    
    return 0;
}
/*
    Time Complexity: O(N*N)

    Reason: At max, there will be (half of, due to triangle) N*N calls of recursion.

    Space Complexity: O(N) + O(N*N)

    Reason: We are using a recursion stack space: O((N),
    where N is the path length and an external DP Array of size ‘N*N’.
*/