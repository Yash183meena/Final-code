//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string &s1, string &s2) {
        // code here
        int n=s1.size(),m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        for(int i=n;i>=0;i--){
            for(int j=m;j>=0;j--){
                
                if(i==n){
                    dp[i][j] = m-j;
                }
                
                else if(j==m){
                    dp[i][j] = n-i;
                }
                
                else if( s1[i] == s2[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                }
                
                else{
                    dp[i][j] = 1 + min(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        
        return dp[0][0];
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