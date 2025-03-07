//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    /*You are required to complete below method */
    
    int solve(int i,int j,string &s,vector<vector<int>>&dp){
        
        if(i > j){
            return 0;
        }
        
        if(i == j){
            return 1;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(s[i] == s[j]){
            return dp[i][j] = 1 + solve(i+1,j,s,dp) + solve(i,j-1,s,dp);
        }
        
        return dp[i][j] = solve(i+1,j,s,dp) + solve(i,j-1,s,dp) - solve(i+1,j-1,s,dp);
        
    }
    
    int countPS(string &s) {
        // Your code here
        
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        
        return solve(0,n-1,s,dp);
    }
};


//{ Driver Code Starts.
//  Driver program
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.countPS(str);
        cout << ans << endl;
    }
}
// } Driver Code Ends