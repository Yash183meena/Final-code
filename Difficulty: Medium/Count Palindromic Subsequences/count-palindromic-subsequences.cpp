//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete below method */
    
    int solve(string &s,int i,int j,vector<vector<int>>&dp){
        
        if( i== j ){
            return 1;
        }
        
        if(i>j){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(s[i] == s[j]){
            return dp[i][j] = 1 + solve(s,i+1,j,dp) + solve(s,i,j-1,dp);
        }
        
        return dp[i][j] = solve(s,i+1,j,dp) + solve(s,i,j-1,dp) - solve(s,i+1,j-1,dp);
    }
    
    int countPS(string &s) {
        // Your code here
        
        int n = s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        
        return solve(s,0,n-1,dp);
        
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