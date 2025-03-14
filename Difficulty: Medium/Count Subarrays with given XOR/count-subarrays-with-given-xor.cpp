//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        
        long long cnt=0;
        
        long xor_prefix=0;
        
        map<int,int>hash;
        
        hash[0]=1;
        
        for(int i=0;i<arr.size();i++){
            
            xor_prefix=xor_prefix^arr[i];
            
            cnt+=hash[xor_prefix^k];
            
            hash[xor_prefix]++;
            
        }
        
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore(); // Ignore the newline after the number of test cases

    while (tc-- > 0) {
        string input;
        getline(cin, input); // Read the whole line for the array

        stringstream ss(input);
        vector<int> arr;
        int num;

        while (ss >> num) {
            arr.push_back(num); // Push numbers into the vector
        }

        int k;
        cin >> k;
        cin.ignore(); // Ignore the newline after k

        Solution obj;
        cout << obj.subarrayXor(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends