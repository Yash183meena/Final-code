//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSubarrays(vector<int> &arr, int k) {
        // code here
        
        map<int,int>hash;
        int n=arr.size();
        int prefix=0,subarray=0;
        
        
        for(int i=0;i<n;i++){
            
            prefix+= arr[i];
            
            if(prefix==k){
                subarray++;
            }
            
            if(hash.find(prefix-k)!=hash.end()){
                subarray+=hash[prefix-k];
            }
            
            hash[prefix]++;
            
        }
        
        return subarray;
    
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
        cout << obj.countSubarrays(arr, k);
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends