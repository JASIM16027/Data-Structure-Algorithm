#include<bits/stdc++.h>
using namespace std;
void subsetSum(int n,int arr[], int range, vector<vector<int>>&dp, vector<int>&v){
    for(int j=0;j<=range;j++){
        dp[0][j] = 0;
    }
    for(int i=0;i<=n; i++){
        dp[i][0]=1;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=range;j++){
            if (arr[i-1]<=j)
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    for(int j = 0;j<=range/2;j++){
        if (dp[n][j]==1)
            v.push_back(j);
    }

}
using namespace std;
int main(){
    int arr[] = {1,6,11,5};
    vector<int>v;
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 0;
    
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    vector<vector<int>>dp(n+1, vector<int>(sum+1, 0));
    subsetSum(n, arr, sum,dp, v);
    //for(auto it: v)cout<<it<<" ";
    int mini = INT_MAX;
    for(auto it:v){
        mini = min(mini,sum - 2*it); // sum-s1-s1 //(s2-s1) s2 = sum-s1
    }
    cout<<mini<<endl;
}