//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    bool check(string &s,int i,int j,vector<vector<int>>&dp){
        
        if(i >= j){
            return true;
        }    
        
        if(s[i] == s[j]){
            return dp[i][j] = check(s,i+1,j-1,dp);
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        return dp[i][j] = false;
    }
    
    string longestPalindrome(string s) {
        // code here
        
        int len=INT_MIN,n=s.size();
        string str;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                
                if(check(s,i,j,dp)){
                    
                    int currLen = max(len,j-i+1);
                    
                    if(currLen > len){
                        len=max(len,currLen);
                        str = s.substr(i,currLen);
                    }
                }
            }
        }
        
        return str;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.longestPalindrome(S) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends