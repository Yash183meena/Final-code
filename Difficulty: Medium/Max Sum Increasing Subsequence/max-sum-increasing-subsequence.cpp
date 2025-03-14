//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    
    int solve(int idx,int prev,vector<int>& arr,vector<vector<int>>&dp){
        
        if(idx>=arr.size()){
            return 0;
        }
        
        if(dp[idx][prev+1]!=-1){
            return dp[idx][prev+1];
        }
        
        int take=0,not_take=0;
        
        if( prev==-1 || arr[idx] > arr[prev] ){
            take+=arr[idx] + solve(idx+1,idx,arr,dp);
        }
        
        not_take=solve(idx+1,prev,arr,dp);
        
        return dp[idx][prev+1]=max(take,not_take);
        
    }
    
    int maxSumIS(vector<int>& arr) {
        // Your code goes here
        
        int n=arr.size();
        
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        
        return solve(0,-1,arr,dp);
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.maxSumIS(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends