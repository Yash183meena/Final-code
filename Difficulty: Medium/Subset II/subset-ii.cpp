//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {

  public:
  
    void solve(int idx,vector<int>&vec,set<vector<int>>&st,vector<int>& nums){
        
        if(idx >= nums.size()){
            st.insert(vec);
            return;
        }
        
        for(int i=idx;i<nums.size();i++){
            
            vec.push_back(nums[i]);
            
            st.insert(vec);
            
            solve(i+1,vec,st,nums);
            
            //backtraking
            vec.pop_back();
        }
    }
    
    vector<vector<int>> printUniqueSubsets(vector<int>& nums) {
        // Write your code here
        
        vector<vector<int>>ans;
        set<vector<int>>st;
        vector<int>vec;
        sort(nums.begin(),nums.end());
        solve(0,vec,st,nums);
        ans.push_back({});
        
        
        for(auto li :st){
            ans.push_back(li);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;
        vector<vector<int>> ans = obj.printUniqueSubsets(nums);
        sort(ans.begin(), ans.end());
        //   printAns(ans);
        cout << "[ ";
        for (int i = 0; i < ans.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " ";
            cout << "]";
        }
        cout << " ]\n";

        // cout<< "~\n";
    
cout << "~" << "\n";
}

    return 0;
}

// } Driver Code Ends