#include<bits/stdc++.h>
using namespace std;

int Max_uniquePath(int i, int j){
    if(i==0 && j==0){
        return 1;
    }

    if(i<0 || j<0){
        return 0;
    }

    int up = Max_uniquePath(i-1,j);
    int left = Max_uniquePath(i,j-1);

    return up+left;
}
int main(){
    int n,m;
    cin>>n>>m;
    cout<<Max_uniquePath(n-1,m-1)<<endl;
    return 0;
}