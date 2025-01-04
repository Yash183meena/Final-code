//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    
    int solve(string& s, int k){
        
        int substrings=0,left=0,right=0;
        map<char,int>hash;
        
        for(right=0;right<s.size();right++){
            
            hash[s[right]]++;
            
            while(left<=right && hash.size() > k){
                
                hash[s[left]]--;
                
                if(hash[s[left]]==0){
                    hash.erase(s[left]);
                }
                
                left++;
            }
            
            substrings+=(right-left+1);
            
        }
        
        return substrings;
    }
    
    int countSubstr(string& s, int k) {
        // code here.
        
        return solve(s,k) - solve(s,k-1);
        
        return 0;
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