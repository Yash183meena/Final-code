//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int findSubArraySum(int k, vector<int> &arr) {
        // code here
        
        map<int,int>mp;
        int prefix=0,ans=0;
        
        for(int i=0;i<arr.size();i++){
            
            prefix+=arr[i];
            
            if(prefix==k){
                ans++;
            }
            
            ans+=mp[prefix-k];
            mp[prefix]++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.findSubArraySum(k, arr);
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends