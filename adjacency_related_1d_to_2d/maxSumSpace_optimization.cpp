#include<bits/stdc++.h>
using namespace std;

int maxSumTabulation(int arr[], int n){
    int prev1 = arr[0];
    int prev2 = 0;
    int curi=0;

    for(int i=1;i<n;i++){
        int pick=arr[i];
        if (i>1){
            pick+=prev2;
        }
        int notpick = prev1;

        curi = max(pick,notpick);
        prev2 = prev1;
        prev1 = curi;
        
        
    }

    return prev1;
}
int main(){
    int arr[] = {2,1,4,9};
    int n = sizeof(arr)/sizeof(arr[0]);

    int res = maxSumTabulation(arr,n);
    cout<<res<<endl;
    return 0;
}

/*
Time Complexity: O(N)

Reason: We are running a simple iterative loop

Space Complexity: O(1)

Reason: We are not using any extra space.

*/