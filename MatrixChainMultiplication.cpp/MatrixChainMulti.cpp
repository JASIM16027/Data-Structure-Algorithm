#include<bits/stdc++.h>
using namespace std;
int MatrixChainMultiplication(int arr[], int i, int j,vector<vector<int>>&dp){
    if (i>=j)return 0;
    int mini = INT_MAX;
    if (dp[i][j]!=-1) return dp[i][j];
    for(int k=i;k<j;k++){
        
        
        int temp_ans = MatrixChainMultiplication(arr,i,k,dp)
        + MatrixChainMultiplication(arr,k+1,j,dp)+arr[i-1]+arr[k]+arr[j];
        mini = min(mini,temp_ans);
        dp[i][j]  =mini;
    }
    for(auto it:dp)
        for(auto i:it)cout<<i<<" ";
        cout<<endl;
    return dp[i][j];
}
int main(){
    int arr[]={40,20,30,10,30};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<vector<int>>dp(n,vector<int>(n,-1));
    cout<<MatrixChainMultiplication(arr,1,n-1,dp)<<endl;
    return 0;
}