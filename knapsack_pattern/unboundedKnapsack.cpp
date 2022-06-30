#include<bits/stdc++.h>
using namespace std;
int unboundedKnapsack(int ind, int wt[], int val[], int w, vector<vector<int>>&dp){
    if (ind==0) return (w/wt[0])*val[0];
    if (dp[ind][w]!=-1) return dp[ind][w];
    int nottake = 0 + unboundedKnapsack(ind-1,wt,val,w,dp);
    int take = INT_MIN;
    if (wt[ind]<=w){
        take = val[ind]+unboundedKnapsack(ind,wt,val,w-wt[ind],dp);
    }

    return dp[ind][w] = max(nottake, take);
}
int main(){

    int wt[] = {2,4,6};
    int val[] = {10,21, 16};
    int w = 10;
    int n = sizeof(wt)/sizeof(wt[0]);
    vector<vector<int>>dp(n,vector<int>(w+1,-1));
    cout<<unboundedKnapsack(n-1, wt,val,w,dp)<<endl;
}