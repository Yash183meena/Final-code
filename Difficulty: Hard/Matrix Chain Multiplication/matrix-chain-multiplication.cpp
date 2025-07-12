class Solution {
  public:
  
    int solve(int i,int j,vector<int>&arr,vector<vector<int>>&dp){
        
        if( i>=j){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int mini=INT_MAX;
        
        for(int k=i;k<j;k++){
            
            int oper = arr[i-1]*arr[k]*arr[j] + solve(i,k,arr,dp) + solve(k+1,j,arr,dp);
            
            mini = min(mini,oper);
        }
        
        return dp[i][j] = mini;
    }
    
    int matrixMultiplication(vector<int> &arr) {
        // code here
        
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        
        return solve(1,n-1,arr,dp);
    }
};