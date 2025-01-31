//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(int i,int j,vector<vector<int>>& arr,vector<vector<int>>&dp){
        
        if(i == arr.size()-1){
            
            return arr[i][j];
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int a=INT_MIN,b=INT_MIN,c=INT_MIN;
        
        if(j!=0){
            a = arr[i][j] + solve(i+1,0,arr,dp);
        }
        
        if(j!=1){
            b = arr[i][j] + solve(i+1,1,arr,dp);
        }
        
        if(j!=2){
            c = arr[i][j] + solve(i+1,2,arr,dp);
        }
        
        return dp[i][j] = max(a,max(b,c));
        
    }
    
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(4,-1));
        int ans=INT_MIN;
        
        for(int i=0;i<=2;i++){
            ans=max(ans,solve(0,i,arr,dp));
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