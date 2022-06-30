#include<bits/stdc++.h>
using namespace std;
int maxSumTabulation(int arr[], int n,vector<int>&dp){
    dp[0] = arr[0];
    for(int i=1;i<n;i++){
        int pick=arr[i];
        if (i>1){
            pick+=dp[i-2];
        }
        int notpick = dp[i-1];

        dp[i] = max(pick,notpick);
        
    }

    return dp[n-1];
}
int main(){
    int arr[] = {2,1,4,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int>dp(n,-1);
    int res = maxSumTabulation(arr,n,dp);
    cout<<res<<endl;
    return 0;
}