//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    void solve(string s,string str,int index,set<string>&st){
        
        
        if(index>=s.size()){
            st.insert(str);
            return;
        }
        
        for(int i=index;i<s.size();i++){
            
            swap(s[index],s[i]);
            str.push_back(s[index]);
            
            solve(s,str,index+1,st);
            
            swap(s[i],s[index]);
            str.pop_back();
        }
    }
    
    vector<string> findPermutation(string &s) {
        // Code here there
        set<string>st;
        vector<string>vec;
        
        solve(s,"",0,st);
        
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