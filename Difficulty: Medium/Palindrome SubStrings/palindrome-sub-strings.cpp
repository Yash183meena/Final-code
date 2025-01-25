//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// User function Template for C++

class Solution {
  public:
  
    bool isPalindrome(string &s,int i,int j,vector<vector<int>>&dp){
        
        if(i>j){
            return true; 
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(s[i] == s[j]){
            return dp[i][j] = isPalindrome(s,i+1,j-1,dp);
        }
        
        return dp[i][j] = false;
    }
    
    int countPS(string &s) {
        // code here
        
        int n=s.size();
        int palindromes=0;
        
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                
                if(isPalindrome(s,i,j,dp)){
                    palindromes++;
                }
            }
        }
        
        
        return palindromes;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.countPS(s) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends