#include<bits/stdc++.h>
using namespace std;
void lcs(string &s, string &subs){
    int row = s.length();
    int col = subs.length();

    vector<vector<int>>dp(row+1,vector<int>(col+1,0));
    int ans = 0;
    for(int i=0; i<=row;i++) dp[i][0] = 0;
    for(int j=0; j<=col;j++) dp[0][j] = 0;

    for(int i=1; i<=row;i++){
        for(int j=1; j<=col;j++){
             
            if (s[i-1]==subs[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                ans = max(ans, dp[i][j]);
            }
                
            else
                dp[i][j] = 0;
        }

    }
    cout<<ans<<endl;
    /*
    int ln = ans;
    int i = row, j=col;
    string ss = "";
    for(int i=0;i<ln;i++) 
        ss+="$";

    while (i>0 & j>0){
        if (s[i-1] == subs[j-1]){
            ss[ln-1]= s[i-1];
            ln--;
            i--;
            j--;
        }
        i--;
        j--;
    }

    for(auto it:ss)cout<<it;
*/
}
int main(){
    string s = "abcdfg";
    string subs = "cdg";
    lcs(s,subs);
}