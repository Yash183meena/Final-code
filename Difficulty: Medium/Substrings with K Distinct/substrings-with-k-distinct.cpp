//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int countSubstr(string& s, int k) {
        // code here.
        int i=0,j=0,ans=0,ans1=0;
        map<char,int>hash;
        
        for(j=0;j<s.size();j++){
            
            hash[s[j]]++;
            
            while(i<s.size() && hash.size()>k){
                
                hash[s[i]]--;
                
                if(hash[s[i]]==0){
                    hash.erase(s[i]);
                }
                
                i++;
            }
            
            ans+=j-i+1;
            
        }
        
        hash.clear();
        i=0;
        for(j=0;j<s.size();j++){
            
            hash[s[j]]++;
            
            while(i<s.size() && hash.size()>k-1){
                
                hash[s[i]]--;
                
                if(hash[s[i]]==0){
                    hash.erase(s[i]);
                }
                
                i++;
            }
            
            ans1+=j-i+1;
            
        }
        
        return ans-ans1;
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