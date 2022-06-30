#include<bits/stdc++.h>
using namespace std;

int isPalindrome(string &s, int i, int j){
    while (i<j){
        if (s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}


int PalindromePartition(string &s, int i, int j, vector<vector<int>>&dp){
    if (i>=j) return 0;
    if (isPalindrome(s,i,j)==true) {
    
        return 0;

    }
            if (dp[i][j]!=-1) return dp[i][j];
    int mini = INT_MAX;
    for(int k=i;k<j;k++){
        int tempans = 1+ PalindromePartition(s,i,k,dp)+PalindromePartition(s,k+1,j,dp);
        if (tempans<mini){
            mini = tempans;
            dp[i][j] = mini;
        }
    }
    return dp[i][j];
}
int main(){
    string s = "nnnitin";
    int n = s.length();
    vector<vector<int>>dp(n,vector<int>(n,-1));
    cout<<PalindromePartition(s, 0, s.length()-1,dp);
    return 0;
}