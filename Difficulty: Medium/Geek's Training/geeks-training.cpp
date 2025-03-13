//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(int i,int j,vector<vector<int>>& arr,vector<vector<int>>&dp){
        
        if(i>=arr.size() || j>=arr[0].size()){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int r=0,l=0,f=0;
        
        //for running 
        if(j==0){
            r = arr[i][0] + max(solve(i+1,1,arr,dp),solve(i+1,2,arr,dp));
        }
        
        //for fighting
        else if(j==1){
            f = arr[i][1] + max(solve(i+1,0,arr,dp),solve(i+1,2,arr,dp));
        }
        
        //for learning
        else if(j==2){
            l = arr[i][2] + max(solve(i+1,0,arr,dp),solve(i+1,1,arr,dp));
        }
        
        return dp[i][j]=max({r,f,l});
    }
    
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(4,-1));
        int ans=INT_MIN;
        
        for(int j=0;j<3;j++){
            ans=max(ans,solve(0,j,arr,dp));
        }
        
        return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends