#include<bits/stdc++.h>
using namespace std;
int dp[102][1002];

int knapsack(int wt[], int val[],int w, int n){
    for(int j=0;j<=w;j++) dp[0][j]=0;
    for(int i=0;i<=n;i++)dp[i][0] = 1;
    
    for(int i=1; i<=n;i++){
        for(int j=1;j<=w;j++){
           
            if (wt[i-1]<=j){
                dp[i][j] = dp[i][j-wt[i-1]]+dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }

        }
    }
    for(int i =0;i<=n;i++){
        for(int j=0;j<=w;j++)cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    
    return dp[n][w];

}
int main(){
    int wt[]={1,2,6,7};
    int val[]={1,10,7,8};
    int w = 8;
    memset(dp,0, sizeof(dp));
    int n = sizeof(wt)/sizeof(wt[0]);
    cout<<knapsack(wt, val, w, n)<<endl;
    return 0;
}