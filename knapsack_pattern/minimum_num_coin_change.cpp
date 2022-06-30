#include<bits/stdc++.h>
using namespace std;

int CoinChange(int ind,int coins[], int t, vector<vector<int>>&dp){
    if (ind==0){
        if (t%coins[0]==0) return t/coins[0];
        else return 1e9;
    }
    
    if (dp[ind][t]!=-1) return dp[ind][t];
    int notpick = 0 + CoinChange(ind-1,coins, t,dp);
    int pick = INT_MAX;
    if (coins[ind]<=t){ 
        pick = 1 + CoinChange(ind, coins, t-coins[ind],dp);

    }

    return dp[ind][t] = min(pick, notpick);
}
int main(){
    int coins[] = {1,2,3};
    int n = sizeof(coins)/sizeof(coins[0]);
    int target= 10;
    vector<vector<int>>dp(n, vector<int>(target+1,-1));
    cout<<CoinChange(n-1,coins, target,dp)<<endl;
    return 0;
}