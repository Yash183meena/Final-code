//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find length of shortest common supersequence of two strings.
    int solve(string &s1, string &s2,int i,int j,vector<vector<int>>&dp){
        
        if(i >=s1.size()){
            return s2.size()-j;
        }    
        
        if(j >= s2.size()){
            return s1.size()-i;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(s1[i] == s2[j]){
            return dp[i][j] = 1 + solve(s1,s2,i+1,j+1,dp);
        }
        
        int taking_the_s1 = 1 + solve(s1,s2,i+1,j,dp);
        
        int taking_the_s2 = 1 + solve(s1,s2,i,j+1,dp);
        
        return dp[i][j] = min(taking_the_s1,taking_the_s2);
    }
    
    int shortestCommonSupersequence(string &s1, string &s2) {
        // code here
        
        int n=s1.size();
        int m=s2.size();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(s1,s2,0,0,dp);
    }
};

//{ Driver Code Starts.

int main() {

    int t;

    // taking total testcases
    cin >> t;
    while (t--) {
        string X, Y;
        // taking String X and Y
        cin >> X >> Y;

        // calling function shortestCommonSupersequence()
        Solution obj;
        cout << obj.shortestCommonSupersequence(X, Y) << endl;
    }
    return 0;
}

// } Driver Code Ends