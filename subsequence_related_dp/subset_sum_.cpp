#include<bits/stdc++.h>
using namespace std;
bool SubsetSum(int arr[], int n, int target){
    if (target==0) return true;
    if (n==0) return arr[0]==target;
    bool nottake = SubsetSum(arr,n-1,target);
    bool take = false;
    if (target>=arr[n]){
        take = SubsetSum(arr, n-1,target-arr[n]);
    }
    
    return take || nottake;
}
int main(){
    int n;
    cin>>n;
    int arr[n+1];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int target;
    cin>>target;
    cout<<SubsetSum(arr,n-1, target)<<endl;
    return 0;
}