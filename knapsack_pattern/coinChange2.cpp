#include<bits/stdc++.h>
using namespace std;

int CoinChange(int ind,int coins[], int t, vector<vector<int>>&dp){
    if (ind==0){
        return (t%coins[0]==0);
    
    }
    
    if (dp[ind][t]!=-1) return dp[ind][t];
    int notpick = CoinChange(ind-1,coins, t,dp);
    int pick = 0;
    if (coins[ind]<=t){ 
        pick = CoinChange(ind, coins, t-coins[ind],dp);

    }

    return dp[ind][t] = pick+notpick;
}
int main(){
    int coins[] = {1,2,3};
    int n = sizeof(coins)/sizeof(coins[0]);
    int target= 7;
    vector<vector<int>>dp(n, vector<int>(target+1,-1));
    cout<<CoinChange(n-1,coins, target,dp)<<endl;
    return 0;
}