//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    
    bool solve(vector<int>& arr, int target,int idx,vector<vector<int>>&dp){
        
        if(target == 0){
            return true;
        }
        
        if(idx>=arr.size() || target<0){
            return false;
        }
        
        if(dp[idx][target]!=-1){
            return dp[idx][target];
        }
        
        bool take = solve(arr,target-arr[idx],idx+1,dp);
        
        bool not_take=solve(arr,target,idx+1,dp);
        
        return dp[idx][target] = take || not_take;
    }
    
    bool isSubsetSum(vector<int>& arr, int target) {
        // code here
        
        int n=arr.size();
        
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        
        return solve(arr,target,0,dp);
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends