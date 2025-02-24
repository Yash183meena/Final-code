//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  
    int function(string& s, int k){
        
        int substrings=0;
        
        int left=0,right;
        map<char,int>hash;
        
        for(right=0;right<s.size();right++){
            
            hash[s[right]]++;
            
            while(hash.size() > k){
                
                hash[s[left]]--;
                
                if(hash[s[left]]==0){
                    hash.erase(s[left]);
                }
                
                left++;
            }
            
            substrings+=right-left+1;
        }
        
        return substrings;
    }
    
    int countSubstr(string& s, int k) {
        // code here.
        
        return function(s,k)-function(s,k-1);
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
        cout << ob.countSubstr(s, k) << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends