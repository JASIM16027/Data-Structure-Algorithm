#include<bits/stdc++.h>
using namespace std;
int main(){
    string s = "abcdfg";
    string subs = "akdflg";
    int n = s.length();
    int m = subs.length();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    //for(int i=0;i<=n;i++)dp[i][0]=0;
    //for(int j=0;j<=m;j++)dp[0][j]=0;

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if (i==0||j==0) dp[i][j]=0;
            else if (s[i-1]==subs[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }

        }
    }

    for(auto it: dp){
        for(auto i: it)cout<<i<<" ";
        cout<<endl;
    }
    cout<<dp[n][m]<<endl;
    int ln = dp[n][m];
    string ss = "";
    for(int i=0;i<ln;i++) 
        ss+="$";
    int i = n, j=m;
    while (i>0 & j>0){
        if (s[i-1] == subs[j-1]){
            ss[ln-1]= s[i-1];
            ln--;
            i--;
            j--;
        }
        else if (dp[i-1][j]>dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }

    for(auto it:ss)cout<<it;
   
}