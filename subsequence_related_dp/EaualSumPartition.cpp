#include <bits/stdc++.h>
using namespace std;

bool subsetSum(int ind, int arr[], int target,vector<vector<int>>&dp)
{
   
    if (target == 0)
        {
            return true;
        }
    if (ind==0)
        return target==arr[ind];

    if (dp[ind][target]!=-1) return dp[ind][target];

    bool nottaken = subsetSum(ind - 1, arr, target,dp);
    bool taken = false;
    if (target >= arr[ind])
    {
        taken = subsetSum(ind - 1, arr,target - arr[ind],dp);
    }

    return dp[ind][target] = taken || nottaken;
}
bool EqualSumPartition(int arr[], int n)
{
    int total_sum = 0;
    for (int i = 0; i < n; i++)
    {
        total_sum += arr[i];
    }
    if (total_sum % 2==1 )
        return false;
    else{
        int target = total_sum / 2;
        vector<vector<int>>dp(n, vector<int>(target+1,-1));

        return subsetSum(n-1,arr, target,dp);
    }
    
}
int main()
{
    int arr[] = {2,3,3,3,4,6,7};
    int n = sizeof(arr) / sizeof(arr[0]);
    if (EqualSumPartition(arr, n))
    {
        cout << "Equalsum partition is possible" << endl;
    }
    else
    {
        cout << "Equalsum partition is not possible" << endl;
    }

    return 0;
}