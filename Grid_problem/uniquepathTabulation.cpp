#include<bits/stdc++.h>
using namespace std;
int main(){

    int n,m;
    cin>>n>>m;
    vector<vector<int>>dp(n, vector<int>(m,-1));
    //for(int i=0; i<n;i++) dp[i][0] = 1;
    //for(int j=0;j<m;j++) dp[0][j] = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if (i==0) dp[i][j] = 1;
            else if (j==0) dp[i][j] = 1;

            else{
                dp[i][j] = dp[i-1][j]+dp[i][j-1];

            }
        }
    }

    cout<<dp[n-1][m-1]<<endl;
    return 0;
}