//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(int i,int j,vector<vector<int>>& arr,vector<vector<int>>&dp){
        
        if(i==arr.size()-1){
            return arr[i][j];
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int a=INT_MIN;
        
        for(int col=0;col<3;col++){
            if(col!=j && i+1<arr.size()){
                a=max(a,arr[i][j] + solve(i+1,col,arr,dp));
            }
        }
        
        return dp[i][j]=a;
    }
    
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        int score=INT_MIN;
        
        vector<vector<int>>dp(arr.size()+1,vector<int>(4,-1));
        
        for(int j=0;j<arr[0].size();j++){
            score=max(score,solve(0,j,arr,dp));
        }
        
        return score;
    
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