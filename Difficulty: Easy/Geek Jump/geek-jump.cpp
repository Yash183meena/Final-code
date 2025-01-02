//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int solve(vector<int>& height, int n,int idx,vector<int>&dp){
        
        if(idx==n-1){
            return 0;
        }
        
        if(dp[idx]!=-1){
            return dp[idx];
        }
        
        int one_step=INT_MAX,two_step=INT_MAX;
        
        if(idx+1 < n){
            one_step = abs(height[idx]-height[idx+1]) + solve(height,n,idx+1,dp);
        }
        
        if(idx+2 < n){
            two_step = abs(height[idx+2]-height[idx]) + solve(height,n,idx+2,dp);
        }
        
        return dp[idx]=min(one_step,two_step);
    }
    
    
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int>dp(n+1,-1);
        
        return  solve(height,n,0,dp);
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends