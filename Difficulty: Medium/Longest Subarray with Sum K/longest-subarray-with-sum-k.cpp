//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        map<int,int>hash;
        int prefix=0;
        int len=0;
        
        for(int i=0;i<arr.size();i++){
            
            prefix+=arr[i];
            
            if(prefix==k){
                len=max(i+1,len);
            }
            
            if(hash.find(prefix-k)!=hash.end()){
                len=max(len,i-hash[prefix-k]);
            }
            
            if(hash.find(prefix)==hash.end()){
                hash[prefix]=i;
            }
        }
        
        return len;
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
        cout << solution.longestSubarray(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends