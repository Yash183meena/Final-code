//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    
    bool solve(vector<int>& arr, int target,vector<vector<int>>&dp,int idx){
        
        if(target == 0){
            return true;
        }
        
        if(idx >= arr.size() || target<0 ){
            return false;
        }
        
        if(dp[idx][target]!=-1){
            return dp[idx][target];
        }
        
        bool include = solve(arr,target-arr[idx],dp,idx+1);
        
        bool exclude = solve(arr,target,dp,idx+1);
        
        return dp[idx][target] = include || exclude;
    }
    
    bool isSubsetSum(vector<int>& arr, int target) {
        // code here
        
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return solve(arr,target,dp,0);
        
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