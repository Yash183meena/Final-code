//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void solve(string &s,int idx,set<string>&vec){
        
        if(idx>=s.size()){
            vec.insert(s);
            return;
        }
        
        for(int i=idx;i<s.size();i++){
            swap(s[idx],s[i]);
            solve(s,idx+1,vec);
            swap(s[idx],s[i]);
        }
    }
    vector<string> findPermutation(string &s) {
        // Code here there
        
        set<string>vec;
        vector<string>ans;
        solve(s,0,vec);
        for(auto str : vec){
            ans.push_back(str);
        }
        
        
        return ans;
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