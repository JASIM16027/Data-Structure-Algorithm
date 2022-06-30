#include<bits/stdc++.h>
using namespace std;

int dp[102][1002];

int knapsack(int wt[], int val[],int w, int n){
    
    if (w==0||n==0) return 0;
    if (dp[n][w]!=-1) return dp[n][w];
    if (wt[n-1]<=w){
        
        return dp[n][w] = max(val[n-1]+knapsack(wt,val,w-wt[n-1],n-1), knapsack(wt,val,w,n-1));
    }
    else if(wt[n-1]>w){
        return dp[n][w] = knapsack(wt,val,w,n-1);
    }
    return dp[n][w];

}
int main(){
    int wt[]={1,3,4,5};
    int val[]={1,4,5,7};
    int w = 7;
    memset(dp,-1, sizeof(dp));
    int n = sizeof(wt)/sizeof(wt[0]);
    cout<<knapsack(wt, val, w, n)<<endl;
    return 0;
}