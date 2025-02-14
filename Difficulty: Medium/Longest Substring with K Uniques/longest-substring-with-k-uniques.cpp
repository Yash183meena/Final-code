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
        
        //question of the sliding window
        
        int left=0,window=-1;
        map<char,int>hash;
        
        for(int right=0;right<s.size();right++){
            
            hash[s[right]]++;
            
            while(hash.size() > k){
                
                hash[s[left]]--;
                
                if(hash[s[left]]==0){
                    hash.erase(s[left]);
                }
                
                left++;
            }
            
            if(hash.size()==k){
                window=max(window,right-left+1);
            }
            
        }
        
        return window;
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