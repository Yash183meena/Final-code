//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    int solve(int idx,vector<int>& arr,int target,vector<vector<int>>&dp){
        
        
        if(target==0 && idx==arr.size()){
            return 1;
        }
        
        if(idx>=arr.size() || target<0){
            return 0;
        }
        
        if(dp[idx][target]!=-1){
            return dp[idx][target];
        }
        
        int take = solve(idx+1,arr,target-arr[idx],dp);
        
        int not_take = solve(idx+1,arr,target,dp);
        
        return dp[idx][target] = (take + not_take);
    }
    
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        
        // let sum of the first subarray = p
        // let sum of the second subarray = q
        int sum=0;
        for(auto ele : arr){
            sum+=ele;
        }
        
        //p+q = sum
        //p-q = d
        
        int target = (sum+d)/2;
        if((sum+d)%2==1){
            return 0;
        }
        
        vector<vector<int>>dp(arr.size()+1,vector<int>(target+1,-1));
        
        return solve(0,arr,target,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countPartitions(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends