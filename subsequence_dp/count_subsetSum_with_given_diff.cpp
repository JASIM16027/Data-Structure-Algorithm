#include<bits/stdc++.h>
using namespace std;

// similar to target sum

int subsetSum(int n,int arr[], int range, vector<vector<int>>&dp, vector<int>&v){
    for(int j=0;j<=range;j++){
        dp[0][j] = 0;
    }
    for(int i=0;i<=n; i++){
        dp[i][0]=1;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=range;j++){
            if (arr[i-1]<=j)
                dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][range];

}
using namespace std;
int main(){
    int arr[] = {1,1,2,3};
    vector<int>v;
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 0;
    int diff = 1;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int s1  = (diff+sum)/2;
    vector<vector<int>>dp(n+1, vector<int>(s1+1, 0));
    cout<<subsetSum(n, arr,s1,dp, v);
    //for(auto it: v)cout<<it<<" ";
    
}