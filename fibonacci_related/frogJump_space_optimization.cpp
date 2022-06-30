#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[] = {30,10,60,10,60,50};
    int n = sizeof(arr)/sizeof(arr[0]);
    //vector<int>dp(n+1,0);
    int prev2 = 0;
    int prev1 = 0;
    int curi = 0;

    int left,right;
    for(int i=1;i<n;i++){
        left = prev1+abs(arr[i]-arr[i-1]);
        right = INT_MAX;
        if (i>1){
            right = prev2+abs(arr[i]-arr[i-2]);
        }

        curi = min(left, right);
        prev2 = prev1;
        prev1 = curi;
    }
    cout<<prev1<<endl;
    return 0;
}
// bottom up approach----->time complexity  0(N) for loop iteration
// space complexity ------> 0(1)