#include<bits/stdc++.h>
using namespace std;
int isPalindrome(int ind, int i, string &s){
    while(ind<i){
        if (s[ind]!=s[i]) return false;
        ind++;
        i--;
    }
    return true;
}
void PalindromicPartition(string &s, int ind,vector<string>&path,
vector<vector<string>>&ans){
       
        if (ind== s.length()){
            ans.push_back(path);
        }

        for(int i=ind;i<s.length();i++){
            if(isPalindrome(ind,i,s)==true){
                path.push_back(s.substr(ind,i-ind+1));
                PalindromicPartition(s,i+1,path,ans);
                path.pop_back();

            }
        }

}
int main(){
    string s = "aabb";
    int n = s.length();    
    vector<vector<string>>ans;
    vector<string>path;
    PalindromicPartition(s,0,path,ans);
     
    for(auto it: ans){
        for(auto i: it)cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
/*
    Time Complexity: O( (2^n) *k*(n/2) )

    Reason: O(2^n) to generate every substring and O(n/2)  to check if the substring 
    generated is a palindrome. O(k) is for inserting the palindromes in another data
    structure, where k  is the average length of the palindrome list.

    Space Complexity: O(k * x)

    Reason: The space complexity can vary depending upon the length of the answer.
    k is the average length of the list of palindromes and if we have x such list of
    palindromes in our final answer. The depth of the recursion tree is n, 
    so the auxiliary space required is equal to the O(n).


*/