//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    void solve(string s, set<string>& st,int index){
        
        if(index>=s.size()){
            st.insert(s);
            return;
        }
        
        
        for(int i=index;i<s.size();i++){
            
            swap(s[index],s[i]);
            
            solve(s,st,index+1);
            
            swap(s[i],s[index]);
        }
    }
    
    vector<string> find_permutation(string s) {
        // Code here there
        set<string>st;
        solve(s,st,0);
        vector<string>permutuations;
        
        for(auto str:st){
            permutuations.push_back(str);
        }
        
        return permutuations;
        
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
        vector<string> ans = ob.find_permutation(S);
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