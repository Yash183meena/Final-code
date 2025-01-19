//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution {
  public:
    int maxLen(vector<int>& arr) {
        // code here
        map<int,int>hash;
        int prefix=0,len=0;
        int k=0;
        
        for(int i=0;i<arr.size();i++){
            
            prefix+=arr[i];
            
            if(prefix==k){
                len=max(len,i+1);
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
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.maxLen(a) << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends