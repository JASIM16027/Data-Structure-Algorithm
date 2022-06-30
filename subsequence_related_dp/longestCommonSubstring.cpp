#include<bits/stdc++.h>
using namespace std;
int lcs(string &s, string &subs){
    int row = s.length();
    int col = subs.length();
    vector<int>prev(col,0), cur(col,0);
    //vector<vector<int>>dp(row+1,vector<int>(col+1,0));
    int ans = 0;
    for(int i=0; i<=row;i++) prev[0] = 0;
    //for(int j=0; j<=col;j++) dp[0][j] = 0;

    for(int i=1; i<=row;i++){
        for(int j=1; j<=col;j++){
             
            if (s[i-1]==subs[j-1]){
                cur[j] = 1 + prev[j-1];
                ans = max(ans, cur[j]);
            }
                
            else
                cur[j] = 0;
        }
        prev = cur;
    }
    
    return ans;

}
int main(){
    string s = "abcdfg";
    string subs = "cdfg";
    cout<<lcs(s,subs)<<endl;
}