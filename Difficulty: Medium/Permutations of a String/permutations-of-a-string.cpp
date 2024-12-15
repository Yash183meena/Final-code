//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    void solve(string s,set<string>&st,int idx){
        
        if(idx>=s.size()){
            st.insert(s);
            return;
        }
        
        for(int i=idx;i<s.size();i++){
            swap(s[idx],s[i]);
            solve(s,st,idx+1);
            swap(s[idx],s[i]);
        }
    }
    
    vector<string> findPermutation(string &s) {
        // Code here there
        
        set<string>st;
        vector<string>vec;
        int idx=0;
        
        solve(s,st,0);
        
        for(auto str:st){
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