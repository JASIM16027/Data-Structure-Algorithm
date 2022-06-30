#include<bits/stdc++.h>
using namespace std;
int frogJump(int arr[], int n, vector<int>&dp){
    if (n==0){
        return 0;
    }
    if (dp[n]!=-1){
        dp[n] = dp[n];
    }

    int left = frogJump(arr,n-1,dp)+abs(arr[n]-arr[n-1]);
    int right = INT_MAX;
    if (n>1){
        right = frogJump(arr,n-2,dp)+abs(arr[n]-arr[n-2]);
    }

    return dp[n] = min(left,right);
}
int main(){
    int arr[] = {30,10,60,10,60,50};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int>dp(n,-1);
    int res = frogJump(arr,n-1,dp);
    cout<<res<<endl;
    //for(auto it: dp)cout<<it<<" ";
    return 0;
}
// top down approach ------>time complexity 0(N)
// space complexity 0(N) for dp array + 0(N) for stack space 
