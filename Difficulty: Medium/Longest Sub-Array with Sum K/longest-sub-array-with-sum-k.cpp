//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int lenOfLongestSubarr(vector<int>& arr, int k) {
        // code here
        
        int prefix=0,ans=0;
        
        map<int,int>hash;
        
        for(int i=0;i<arr.size();i++){
            
            prefix+=arr[i];
            
            if(prefix == k){
                ans=i+1;
            }
            
            if(hash.find(prefix-k)!=hash.end()){
                ans = max(ans,i - hash[prefix-k]);
            }
            
            if(hash.find(prefix) == hash.end()){
                hash[prefix]=i;
            }
            
        }
        
       // cout<<ans;
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.lenOfLongestSubarr(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends