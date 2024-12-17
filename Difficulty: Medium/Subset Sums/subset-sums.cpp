//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    void solve(vector<int>&nums,vector<int>&vec,set<vector<int>>&st,int idx,vector<vector<int>>&stk){
        
        if(idx>=nums.size()){
            return;
        }
        
        for(int i=idx;i<nums.size();i++){
            
            vec.push_back(nums[i]);
            
            solve(nums,vec,st,i+1,stk);
            st.insert(vec);
            stk.push_back(vec);
            
            vec.pop_back();
        }
    }
    
    
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        vector<int>vec;
        vector<vector<int>>stk;
        set<vector<int>>st;
        
        solve(arr,vec,st,0,stk);
        
        vector<int>ans;
        ans.push_back(0);
        
        for(auto li:stk){
            int sum=accumulate(li.begin(),li.end(),0);
            ans.push_back(sum);
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t; // Number of test cases
    cin >> t;
    cin.ignore(); // Ignore the newline after the integer input

    while (t--) {
        vector<int> inputArray;
        string inputLine;

        // Input format: first number n followed by the array elements
        getline(cin, inputLine);
        stringstream inputStream(inputLine);
        int num;
        while (inputStream >> num) {
            inputArray.push_back(num); // Read the array elements from input string
        }

        Solution solutionObject;
        vector<int> result = solutionObject.subsetSums(inputArray);
        sort(result.begin(), result.end());

        for (int i = 0; i < result.size(); i++) {
            if (i != 0)
                cout << " ";
            cout << result[i];
        }
        cout
            << endl
            << "~\n"; // Print results in list format with new line after each test case
    }

    return 0;
}

// } Driver Code Ends