//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
  
    int solve(int i,int j,vector<int> &arr,vector<vector<int>>&dp){
        
        if( i>= j){
            return 0;
            
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int mini=INT_MAX;
        
        for(int k=i;k<j;k++){
            
            int oper=arr[i-1]*arr[k]*arr[j]+solve(i,k,arr,dp)+solve(k+1,j,arr,dp);
            
            mini=min(mini,oper);
        }
        
        return dp[i][j]=mini;
    }
    
    int matrixMultiplication(vector<int> &arr) {
        // code here
        vector<vector<int>>dp(arr.size()+1,vector<int>(arr.size()+1,-1));
        
        return solve(1,arr.size()-1,arr,dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.matrixMultiplication(a) << endl << "~\n";
    }

    return 0;
}

// } Driver Code Ends