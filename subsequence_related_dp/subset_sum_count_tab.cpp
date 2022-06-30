#include<bits/stdc++.h>
using namespace std;

int SubsetCount(int n,int arr[], int t,vector<vector<int>>&dp){
    for(int ind=0;ind<n;ind++)
        dp[ind][0] = 1;
   
    if (arr[0]<=t)
        dp[0][arr[0]] = 1;
        
        
   
    for(int ind = 1;ind<n;ind++){
        for(int tar = 0; tar<=t;tar++){
            int notpick =dp[ind-1][tar];
            int pick = 0;
            if (arr[ind]<=tar)
                pick = dp[ind-1][tar-arr[ind]];
            
            dp[ind][tar] =pick+notpick;
    
        }
    }
    return dp[n-1][t];

}
int main(){
    int arr [] = {1,2,2,3,3,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 8;
    vector<vector<int>>dp(n,vector<int>(target+1,0));
    cout<<SubsetCount(n, arr,target,dp)<<endl;
    for(auto it: dp){
        for(auto i: it)cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}