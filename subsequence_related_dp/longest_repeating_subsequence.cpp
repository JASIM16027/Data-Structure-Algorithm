#include<bits/stdc++.h>
using namespace std;

int longestRepeatingSubsequence(int n, int m,string &s1, string &s2,
vector<vector<int>>&dp){

    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int j=0;j<=m;j++)dp[0][j]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if (s1[i-1]==s2[j-1] && i!=j){
                dp[i][j] = 1+ dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    for(auto it:dp){
        for(auto i:it)cout<<i<<" ";
        cout<<endl;
    }
    return dp[n][m];
}
int main(){
    string s1 = "AABEBCDD";
    string s2 =s1;
    
    int n = s1.length();

    vector<vector<int>>dp(n+1, vector<int>(n+1,0));
    cout<<longestRepeatingSubsequence(n,n,s1,s2,dp)<<endl;
    return 0;
}