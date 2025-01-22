//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // your code here
        
        int left=0,right=0;
        map<char,int>hash;
        int len=INT_MIN;
        
        for(right=0;right<s.size();right++){
            
            hash[s[right]]++;
            
            while(hash.size() > k){
                
                hash[s[left]]--;
                
                if(hash[s[left]] == 0){
                    hash.erase(s[left]);
                }
                
                left++;
            }
            
            if(hash.size()==k){
                len=max(len,right-left+1);
            }
        }
        
        return  len==INT_MIN?-1:len;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends