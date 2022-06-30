#include<bits/stdc++.h>
using namespace std;
int knapsack(int wt[], int val[],int w, int n){
    if (w==0||n==0) return 0;
    int taken=INT_MIN, nottaken =INT_MIN;
    if (wt[n-1]<=w){
        taken =  max(val[n-1]+knapsack(wt,val,w-wt[n-1],n-1), knapsack(wt,val,w,n-1));
    }

    else if(wt[n-1]>w){
        nottaken =  knapsack(wt,val,w,n-1);
    }
    return max(taken, nottaken);

}
int main(){
    int wt[]={1,3,4,5};
    int val[]={1,8,5,7};
    int w = 7;
    int n = sizeof(wt)/sizeof(wt[0]);
    cout<<knapsack(wt, val, w, n)<<endl;
    return 0;
}