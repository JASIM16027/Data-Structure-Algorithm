#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[] = {30,10,60,10,60};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int>dp(n+1,0);
    dp[0]=0;
    int left,right;
    for(int i=1;i<n;i++){
        left = dp[i-1]+abs(arr[i]-arr[i-1]);
        right = INT_MAX;
        if (i>1){
            right = dp[i-2]+abs(arr[i]-arr[i-2]);
        }

        dp[i] = min(left, right);
    }
    cout<<dp[n-1]<<endl;
    return 0;
}
// bottom up approach----->time complexity  0(N) for loop iteration
// space complexity ------> 0(N) for array (dp)