#include<bits/stdc++.h>
using namespace std;

long long int solve(vector<int>&arr){
    long long int prev2 = 0;
    long long int prev1 = arr[0];

    for(int i=1;i<arr.size();i++){
        long long int pick = arr[i];
        if (i>1){
            pick+=prev2;
        }
        long long int notpick = prev1;

        long long int curi = max(pick, notpick);
        prev2 = prev1;
        prev1 = curi;
    }
    return prev1;

}

long long int robStreet(vector<int>&arr, int n){
    vector<int>arr1;
    vector<int>arr2;
    for(int i=0;i<n;i++){
        if (i!=0){
            arr1.push_back(arr[i]);
            
        }
        if (i!=n-1){
            arr2.push_back(arr[i]);
        }
    }

    long long int ans1 = solve(arr1);
    long long int ans2 = solve(arr2);

    return max(ans1,ans2);
}
int main(){
    vector<int>arr{2,3,2};

    cout<<robStreet(arr, arr.size())<<endl;
    return 0;
}