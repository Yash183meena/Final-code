//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  
    bool solve(int idx,vector<int>& arr, int target,vector<vector<int>>&dp){
        
        if(target == 0){
            return true;
        }
        
        if( target<0 || idx>=arr.size() ){
            return false;
        }
        
        if(dp[idx][target]!=-1){
            return dp[idx][target];
        }
        
        bool take= solve(idx+1,arr,target-arr[idx],dp);
        
        bool not_Take = solve(idx+1,arr,target,dp);
        
        return dp[idx][target] = (take || not_Take);
    }
  
    bool isSubsetSum(vector<int>& arr, int target) {
        // code here
        
        
        vector<vector<int>>dp(arr.size()+1,vector<int>(target+1,-1));
        
        return solve(0,arr,target,dp);
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