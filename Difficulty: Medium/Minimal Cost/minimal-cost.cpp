//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int solve(int k, vector<int>& arr,int idx,int n,vector<int>&dp){
        
        if(idx == n-1){
            return 0;
        }
        
        if(dp[idx]!=-1){
            return dp[idx];
        }
        
        int cost=INT_MAX,ans=INT_MAX;
        
        for(int i=idx+1;i<=idx+k;i++){
            
            if(i < n){
                cost = abs(arr[i] - arr[idx]) + solve(k,arr,i,n,dp);
                ans=min(ans,cost);
            }
        }
        
        return dp[idx] = ans;
    } 
    
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        int n=arr.size();
        vector<int>dp(n+1,-1);
        return solve(k,arr,0,n,dp);
        return 0;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends