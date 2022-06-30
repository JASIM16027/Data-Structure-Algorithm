#include<bits/stdc++.h>
using namespace std;

int lcs(int i, int j,string &s, string &sub,vector<vector<int>>&dp ){
    if (i==0 || j ==0) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    else if (s[i-1]==sub[j-1])
     return dp[i][j] = 1+lcs(i-1,j-1,s,sub,dp);
    else{
        return dp[i][j] = max(lcs(i-1,j,s,sub,dp)
        ,lcs(i,j-1,s,sub,dp));
    }
                                  
}
int main(){
    string s = "acdb";
    string s1 = s;
    reverse(s1.begin(),s1.end());

    int len1 = s.length();
    int len2 = s1.length();
    vector<vector<int>>dp(len1+1,vector<int>(len2+1,-1));
    cout<<lcs(len1, len2, s,s1,dp);
}