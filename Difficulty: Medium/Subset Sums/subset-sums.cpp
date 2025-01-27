//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void solve(int idx,vector<int>& arr,vector<vector<int>>&sets,vector<int>vec){
        
        if(idx>=arr.size()){
            return;
        }
        
        for(int i=idx;i<arr.size();i++){
            
            vec.push_back(arr[i]);
            sets.push_back(vec);
            
            solve(i+1,arr,sets,vec);
            
            vec.pop_back();
        }
    }
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        vector<vector<int>>sets;
        vector<int>vec;
        
        solve(0,arr,sets,vec);
        vec.clear();
        vec.push_back(0);
        
        for(auto li : sets){
            int sum=0;
            for(auto ele :li){
                sum+=ele;
            }
            vec.push_back(sum);
        }
        
        sort(begin(vec),end(vec));
        
        for(auto ele:vec){
            cout<<ele<<" ";
        }
        
        return {};
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