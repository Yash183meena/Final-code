//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int mod=1e9;
    
    int solveMem(vector<int>& arr, int target,int idx,int n,vector<vector<int>>&dp){
        
        if(target==0 && idx==n){
            return 1;
        }
        
        if(idx >= arr.size() || target<0 ){
            return 0;
        }
        
        if(dp[idx][target]!=-1){
            return dp[idx][target];
        }
        
        int take=0;
        if(target >= arr[idx]){
            take=solveMem(arr,target-arr[idx],idx+1,n,dp);
        }
        
        int not_take=solveMem(arr,target,idx+1,n,dp);
        
        return dp[idx][target]=(not_take%mod + take%mod)%mod;
    }
    
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        
        return solveMem(arr,target,0,n,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int target;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> target;
        cin.ignore(); // Ignore newline character after target input

        Solution solution;
        cout << solution.perfectSum(arr, target);
        cout << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends