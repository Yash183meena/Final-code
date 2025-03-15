//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    
    //To This Question we have 3 steps
    
    //step1:--->Take the entire array func(i,j)
    //steps2:-->we have to take aall the combination of partion from which we get minimum
        // take the partitions different different using the for loop
    
    //step3: --> Return the minimum 2
    
    int solve(int i,int j,vector<int> &arr,vector<vector<int>>&dp){
        
        if( i == j ){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int mini=INT_MAX;
        
        //loop for partition
        for(int k=i;k<j;k++){
            
            int multiplications = arr[i-1] * arr[k] * arr[j] + 
                 solve(i,k,arr,dp) + solve(k+1,j,arr,dp);
                 
            mini=min(multiplications,mini);
        }
        
        return dp[i][j]=mini;
    }
    
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(1,n-1,arr,dp);
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