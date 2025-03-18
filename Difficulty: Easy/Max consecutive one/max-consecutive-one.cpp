//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int maxConsecutiveCount(vector<int> &arr) {
        // code here
        int one=0,zero=0,z=0,o=0;
        
        for(int i=0;i<arr.size();i++){
            
            if(arr[i]==0){
                z++;
            }
            else{
                z=0;
            }
            
            zero=max(z,zero);
        }
        
        for(int i=0;i<arr.size();i++){
            
            if(arr[i]==1){
                o++;
            }
            else{
                o=0;
            }
            
            one=max(one,o);
        }
        
        return max(zero,one);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.maxConsecutiveCount(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends