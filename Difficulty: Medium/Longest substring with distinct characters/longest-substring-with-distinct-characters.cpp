//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        
        map<char,bool>hash;
        
        int left=0,right=1;
        hash[s[left]]=true;
        
        int len=1;
        
        while(right<s.size()){
            
            if(!hash[s[right]]){
                hash[s[right]]++;
                len=max(len,right-left+1);
                right++;
                
            }
            
            else{
                hash[s[left]]=false;
                left++;
                if(left>right){
                    left=right;
                }
            }
        }
        return len;

    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends