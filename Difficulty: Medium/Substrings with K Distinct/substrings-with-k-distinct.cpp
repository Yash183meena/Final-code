//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  
    int solve(string& s, int k){
        
        int at_most_k = 0;
        map<char,int>hash;
        int i=0;
        
        for(int j=0;j<s.size();j++){
            
            hash[s[j]]++;
            
            //for safe condition
            while(hash.size()>k){
                hash[s[i]]--;
                
                if(hash[s[i]]==0){
                    hash.erase(s[i]);
                }
                
                i++;
            }
            
            at_most_k+=j-i+1;
        }
        
        return at_most_k;
    }
    
    int countSubstr(string& s, int k) {
        // code here.
        map<char,int>hash;
        
        return solve(s,k) - solve(s,k-1);
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