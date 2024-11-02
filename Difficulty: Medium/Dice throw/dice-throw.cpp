//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    long long solveMem(int m, int n, int x,vector<vector<long long>>& dp){
        
        if(x==0 && n==0){
            return 1;
        }
        if(x<0 || n<0){
            return 0;
        }
        if(n==0 && x!=0){
            return 0;
        }
        
        if(n!=0 && x==0){
            return 0;
        }
        
        if(dp[n][x]!=-1){
            return dp[n][x];
        }
        
    
        long long ans=0;
        
        for(int i=1;i<=m;i++){
           
            ans=ans+solveMem(m,n-1,x-i,dp);
            
        }
        
        dp[n][x]=ans;
        return dp[n][x];
    }
    
    long long noOfWays(int m, int n, int x) {
        // code here
        
        vector<vector<long long>>dp(n+1,vector<long long>(x+1,-1));
        
        return solveMem(m,n,x,dp);
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ts;
        getline(cin, ts);
        stringstream ss(ts);
        int number;
        int f = 0;
        int m, n, x;
        while (ss >> number) {
            if (f == 0)
                m = number;
            else if (f == 1)
                n = number;
            else
                x = number;
            f++;
        }

        // cin>>M>>N>>X;

        Solution ob;
        cout << ob.noOfWays(m, n, x) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends