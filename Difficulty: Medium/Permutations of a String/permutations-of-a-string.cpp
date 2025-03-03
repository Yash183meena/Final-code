//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void solve(int idx,string str,set<string>&st){
        
        if(idx >= str.size()){
            st.insert(str);
            return;
        }
        
        for(int i=idx;i<str.size();i++){
            
            swap(str[i],str[idx]);
            solve(idx+1,str,st);
            swap(str[i],str[idx]);
        }
    }
    
    vector<string> findPermutation(string &s) {
        // Code here there
        set<string>st;
        vector<string>vec;
        
        solve(0,s,st);
        
        for(auto str : st){
          vec.push_back(str);
        }
        
        return vec;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends