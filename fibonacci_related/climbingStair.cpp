#include<bits/stdc++.h>
using namespace std;

int climbing(int n, vector<int>&dp){
    if (n<=1){
        return 1;
    }

    if (dp[n]!=0) return dp[n];

    return dp[n] = climbing(n-1,dp)+climbing(n-2,dp);
}
int main(){
    int n;
    cin>>n;
    vector<int>dp(n,0);
    int res = climbing(n,dp);
    cout<<res<<endl;
    return 0;
}

// time complexity 0(n) for run loop for n times
//space complexity (0(n) for stack space + 0(n) for an array) 