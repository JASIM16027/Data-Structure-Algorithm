#include<bits/stdc++.h>
using namespace std;
int SubsetCount(int ind,int arr[], int t,vector<vector<int>>&dp){
    if (t==0) return 1;
    if(ind==0){
        return arr[0]==t;
    }
    if (dp[ind][t]!=-1) return dp[ind][t];
    int notpick = SubsetCount(ind-1,arr,t,dp);
    int pick = 0;
    if (arr[ind]<=t){
        pick = SubsetCount(ind-1,arr, t-arr[ind],dp);
    }
    return dp[ind][t] = pick+notpick;

}
int main(){
    int arr [] = {1,1,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 1;
    vector<vector<int>>dp(n,vector<int>(target+1,-1));
    cout<<SubsetCount(n-1, arr,target,dp)<<endl;
    
    return 0;
}