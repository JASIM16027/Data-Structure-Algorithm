#include<bits/stdc++.h>
using namespace std;
int dp[102][1002];

int knapsack(int wt[], int val[],int w, int n){
    
    for(int i=0; i<n+1;i++){
        for(int j=0;j<w+1;j++){
            if (i==0 || j==0){
                dp[i][j] = 0;
            }
            else if (wt[i-1]<=j){
                dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }

        }
    }
    
    return dp[n][w];

}
int main(){
    int wt[]={1,2,4,5};
    int val[]={1,10,7,8};
    int w = 8;
    memset(dp,0, sizeof(dp));
    int n = sizeof(wt)/sizeof(wt[0]);
    cout<<knapsack(wt, val, w, n)<<endl;
    return 0;
}