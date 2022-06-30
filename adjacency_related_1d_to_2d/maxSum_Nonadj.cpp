#include<bits/stdc++.h>
using namespace std;

int maxSumAdj(int arr[], int n, vector<int>&dp){
    if (n==0) return arr[n];
    if (n<0) return 0;
    if (dp[n]!=-1) return dp[n];
    int pick = arr[n]+maxSumAdj(arr,n-2,dp);
    int notpick = maxSumAdj(arr,n-1,dp);
    return dp[n] = max(pick,notpick);
}
int main(){
    int arr[] = {2,1,4,9};
    int n= sizeof(arr)/sizeof(arr[0]);
    vector<int>dp(n,-1);
    int res = maxSumAdj(arr,n-1,dp);
    cout<<res<<endl;
    return 0;
}